# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2021/11/02 15:12:56 by cybattis          #+#    #+#             #
#   Updated: 2021/12/03 14:04:04 by cybattis         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME 		=	fdf
NAMED 		=	fdf_d
LIBFT		=	libft

# Config
# ****************************************************************************

CC 			=	gcc
INCLUDE		=	-I libft/includes

CFLAGS		=	-Wall -Wextra -O2 -MMD $(HDFLAGS)
DBFLAGS		=	$(CFLAGS) -g3 -fsanitize=address
HDFLAGS		=	$(INCLUDE)
LIBFLAGS	=	-L$(LIBFT) -lft

# Source files
# ****************************************************************************

SRCDIR		=	src/
SRCSFILE	=	fdf.c

SRCS		=	$(addprefix $(SRCDIR), $(SRCSFILE))

OBJSDIR		=	obj/
OBJS		=	$(addprefix $(OBJSDIR), $(notdir $(SRCS:.c=.o)))

OBJSDIRD	=	objd/
OBJSD		=	$(addprefix $(OBJSDIRD), $(notdir $(SRCS:.c=.o)))

DEPENDSD	=	$(OBJSD:.o=.d)
DEPENDS		=	$(OBJS:.o=.d)

# Recipe
# ****************************************************************************

$(OBJSDIR)%.o:	$(SRCDIR)%.c
	@mkdir -p $(OBJSDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

$(OBJSDIRD)%.o:	$(SRCDIR)%.c
	@mkdir -p $(OBJSDIRD)
	@$(CC) $(DBFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

$(NAME):	lib
$(NAME): 	$(OBJS)
	@printf "$(_END)\nCompiled source files\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $@
	@printf "$(_GREEN)Finish compiling $(NAME)!$(_END)\n"

$(NAMED): 	libd
$(NAMED): 	$(OBJSD)
	@printf "$(_END)\nCompiled debug source files\n"
	@$(CC) $(DBFLAGS) $(OBJSD) $(LIBFLAGS) -o $@
	@printf "$(_GREEN)Finish compiling in debug mode$(NAMED)!$(_END)\n"

all:	header $(NAME)

clean:	header
	@printf "$(_YELLOW)Removing object files ...$(_END)\n"
	@rm -rf $(OBJSDIR) $(OBJSDIRD)
	@rm -fr *.dSYM

fclean:	clean
	@printf "$(_RED)Removing Executable ...$(_END)\n"
	@make fclean -C $(LIBFT)
	@rm -rf $(NAME) $(NAMED)

re:		header fclean all

lib:
	@make -C $(LIBFT)

libd:
	@make debug -C $(LIBFT)

debug:	header libd
debug:	$(NAMED)

print-%:	; @echo $* = $($*)

-include $(DEPENDS)
-include $(DEPENDSD)

.PHONY: all clean fclean re debug header stress start

header:
	@printf "\n"
	@printf "$(_CYAN)\t███████╗██████╗ ███████╗$(_END)\n"
	@printf "$(_CYAN)\t██╔════╝██╔══██╗██╔════╝$(_END)\n"
	@printf "$(_CYAN)\t█████╗  ██║  ██║█████╗$(_END)\n"
	@printf "$(_CYAN)\t██╔══╝  ██║  ██║██╔══╝$(_END)\n"
	@printf "$(_CYAN)\t██║     ██████╔╝██║$(_END)\n"
	@printf "$(_CYAN)\t╚═╝     ╚═════╝ ╚═╝$(_END)\n"
	@printf "\n"

# Colors
# ****************************************************************************

_GREY	= \033[30m
_RED	= \033[31m
_GREEN	= \033[32m
_YELLOW	= \033[33m
_BLUE	= \033[34m
_PURPLE	= \033[35m
_CYAN	= \033[36m
_WHITE	= \033[37m
_END	= \033[0m

# ****************************************************************************
