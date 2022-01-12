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
LIB			=	lib
LIBFT		=	libft
MINILIBX	=	mlx_linux

# Config
# ****************************************************************************

CC 			=	gcc -std=c11
CFLAGS		=	-Wall -Werror -Wextra -O2 -MMD $(INCLUDE)
DBFLAGS		=	$(CFLAGS) -g3 -fsanitize=address

LIBFTFLAGS	=	-L $(LIB)/$(LIBFT) -lft
MLXFLAGS	=	$(LIB)/libmlx_Linux.a -L/usr/X11/lib -Imlx_linux -lXext -lX11 -lm -lz

INCLUDE		=	-I $(LIB)/$(LIBFT)/includes -I includes

# Source files
# ****************************************************************************

SRCDIR		=	src/
SRCSFILE	=	fdf.c colors.c draw.c

SRCS		=	$(addprefix $(SRCDIR), $(SRCSFILE))

OBJSDIR		=	obj/
OBJS		=	$(addprefix $(OBJSDIR), $(notdir $(SRCS:.c=.o)))

OBJSDIRD	=	objd/
OBJSD		=	$(addprefix $(OBJSDIRD), $(notdir $(SRCS:.c=.o)))

DEPENDS		=	$(OBJS:.o=.d)
DEPENDSD	=	$(OBJSD:.o=.d)

# Recipe
# ****************************************************************************

all:	$(NAME)

$(NAME): $(OBJS) $(LIB)/$(LIBFT)/$(LIBFT).a
	@printf "$(_END)\nCompiled source files\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFTFLAGS) $(MLXFLAGS) -o $@
	@printf "$(_GREEN)Finish compiling $(NAME)!$(_END)\n"

$(NAMED): $(OBJSD) $(LIB)/$(LIBFT)/$(LIBFT).a
	@printf "$(_END)\nCompiled debug source files\n"
	@$(CC) $(DBFLAGS) $(OBJSD) $(LIBFTFLAGS) $(MLXFLAGS) -o $@
	@printf "$(_GREEN)Finish compiling in debug mode$(NAMED)!$(_END)\n"

$(OBJSDIR)%.o:	$(SRCDIR)%.c
	@mkdir -p $(OBJSDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

$(OBJSDIRD)%.o:	$(SRCDIR)%.c
	@mkdir -p $(OBJSDIRD)
	@$(CC) $(DBFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

$(LIB)/$(LIBFT)/$(LIBFT).a: FORCE
	@$(MAKE) -C $(LIB)/$(LIBFT)
FORCE:;

clean:	header
	@printf "$(_YELLOW)Removing object files ...$(_END)\n"
	@make clean -C $(LIB)/$(LIBFT)
	@rm -rf $(OBJSDIR) $(OBJSDIRD)
	@rm -fr *.dSYM

fclean:	clean
	@printf "$(_RED)Removing Executable ...$(_END)\n"
	@make fclean -C $(LIB)/$(LIBFT)
	@rm -rf $(NAME) $(NAMED)

re:		header fclean all

debug:	header libd
debug:	$(NAMED)

print-%:	; @echo $* = $($*)

-include $(DEPENDS)

.PHONY: all clean fclean re debug header

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
