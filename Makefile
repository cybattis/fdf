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
MINILIBX	=	mlx

# Config
# ****************************************************************************

CC 			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -O2 $(INCLUDE)
DBFLAGS		=	$(CFLAGS) -g3 -fsanitize=address
LIBFTFLAGS	=	-L $(LIB)/$(LIBFT) -lft
LIBFTFLAGSD	=	-L $(LIB)/$(LIBFT) -lft_d

AR_LIBFT	=	$(LIB)/libft.a
AR_LIBFT_D	=	$(LIB)/libft_d.a

OS			=	$(shell uname -s)
ifeq ($(OS), Linux)
	MLXFLAGS	=	-L $(LIB) -lmlx -L/usr/X11/lib -Imlx_linux -lXext -lX11 -lm -lz
else
	MLXFLAGS	=	-L $(LIB)/mlx -lmlx -framework OpenGL -framework AppKit
endif

INCLUDE		=	-I $(LIB)/$(LIBFT)/includes -I includes -I $(LIB)/mlx
DEPS		=	includes/fdf.h $(LIB)/$(LIBFT)/includes/libft.h

# Source files
# ****************************************************************************

DIR_SRCS	=	src
SRCSFILE	=	main.c colors.c colors2.c draw.c draw_line.c draw_circle.c		\
				utils.c	hooks.c	map_parsing.c map.c projection.c world_matrix.c	\
				rotation_matrix.c utils_print.c

SRCS		=	$(addprefix $(DIR_SRCS)/, $(SRCSFILE))

DIR_OBJS	=	obj
OBJS		=	$(addprefix $(DIR_OBJS)/, $(notdir $(SRCS:.c=.o)))
DIR_OBJSD	=	obj_d
OBJSD		=	$(addprefix $(DIR_OBJSD)/, $(notdir $(SRCS:.c=.o)))

# Recipe
# ****************************************************************************

$(DIR_OBJS)/%.o:	$(DIR_SRCS)/%.c $(DEPS) Makefile | $(DIR_OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

$(NAME):	$(AR_LIBFT) $(OBJS)
	@printf "$(_END)\nCompiled source files\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFTFLAGS) $(MLXFLAGS) -o $@
	@printf "$(_GREEN)Finish compiling $(NAME)!$(_END)\n"

# Debug
# =====================
$(DIR_OBJSD)/%.o:	$(DIR_SRCS)/%.c $(DEPS) Makefile | $(DIR_OBJSD)
	@$(CC) $(DBFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

$(NAMED):	$(AR_LIBFT_D) $(OBJSD)
	@printf "$(_END)\nCompiled debug source files\n"
	@$(CC) $(DBFLAGS) $(OBJSD) $(LIBFTFLAGSD) $(MLXFLAGS) -o $@
	@printf "$(_GREEN)Finish compiling in debug mode$(NAMED)!$(_END)\n"

# Action
# =====================

all:	$(NAME)

clean:	header
	@printf "$(_YELLOW)Removing object files ...$(_END)\n"
	@make clean -C $(LIB)/$(LIBFT)
	@rm -rf $(DIR_OBJS) $(DIR_OBJSD)
	@rm -fr *.dSYM

fclean:	clean
	@printf "$(_RED)Removing Executable ...$(_END)\n"
	@make fclean -C $(LIB)/$(LIBFT)
	@rm -rf $(NAME) $(NAMED)

re:		header fclean all

debug:	header
debug:	$(NAMED)

$(AR_LIBFT):
	@$(MAKE) -C $(LIB)/$(LIBFT)

$(AR_LIBFT_D):
	@$(MAKE) debug -C $(LIB)/$(LIBFT)

$(DIR_OBJS):
	@mkdir -p $(DIR_OBJS)

$(DIR_OBJSD):
	@mkdir -p $(DIR_OBJSD)

.PHONY: all clean fclean re debug header

# Misc
# =====================

print-%:	; @echo $* = $($*)

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
