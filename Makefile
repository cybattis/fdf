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
NAME_DBG 		=	fdf_d
LIB			=	lib
LIBFT		=	libft
MINILIBX	=	mlx

# Config
# ****************************************************************************

CC 			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -O2 $(INCLUDE) #-g3 -fsanitize=address
LIBFTFLAGS	=	-L $(LIB)/$(LIBFT) -lft
LIBFTFLAGSD	=	-L $(LIB)/$(LIBFT) -lft_d

OS			=	$(shell uname -s)
ifeq ($(OS), Linux)
	MLXFLAGS	=	-L $(LIB) -lmlx -L/usr/X11/lib -Imlx_linux -lXext -lX11 -lm -lz
else
	MLXFLAGS	=	-L $(LIB)/mlx -lmlx -framework OpenGL -framework AppKit
endif

INCLUDE		=	-I $(LIB)/$(LIBFT)/includes -I includes -I $(LIB)/mlx
DEPS		=	includes/fdf.h $(LIB)/$(LIBFT)/includes/libft.h

AR_LIB		=	$(LIB)/$(LIBFT)/$(LIBFT).a
AR_LIB_DBG	=	$(LIB)/$(LIBFT)/$(LIBFT)_d.a

# Source files
# ****************************************************************************

DIR_SRCS	=	src
SRCSFILE	=	main.c colors.c colors2.c draw.c draw_line.c draw_circle.c	\
				utils.c	hooks.c	map_parsing.c projection.c world_matrix.c	\
				rotation_matrix.c utils_print.c strtrim.c

SRCS		=	$(addprefix $(DIR_SRCS)/, $(SRCSFILE))

DIR_OBJS	=	obj
OBJS		=	$(addprefix $(DIR_OBJS)/, $(notdir $(SRCS:.c=.o)))

# Recipe
# ****************************************************************************

all: header compile

$(DIR_OBJS)/%.o:	$(DIR_SRCS)/%.c $(DEPS) Makefile | $(DIR_OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

$(NAME): $(OBJS) $(AR_LIB)
	@printf "$(_BLUE)\nCompiled source files\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFTFLAGS) $(MLXFLAGS) -o $@
	@printf "$(_GREEN)Finish compiling $(NAME)!$(_END)\n"

$(NAME_DBG): $(OBJS) $(AR_LIB_DBG)
	@printf "$(_BLUE)\nCompiled source files\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFTFLAGSD) $(MLXFLAGS) -o $@
	@printf "$(_GREEN)Finish compiling $(NAME)!$(_END)\n"

compile:
	@$(MAKE) $(NAME) -C .

debug: header
	@$(MAKE) $(NAME_DBG) -C .

clean:	header
	@printf "$(_YELLOW)Removing object files ...$(_END)\n"
	@make clean -C $(LIB)/$(LIBFT)
	@rm -rf $(DIR_OBJS) $(DIR_OBJSD)
	@rm -fr *.dSYM

fclean:	clean
	@printf "$(_RED)Removing Executable ...$(_END)\n"
	@make fclean -C $(LIB)/$(LIBFT)
	@rm -rf $(NAME) $(NAME_DBG)

re:		header fclean all

$(AR_LIB):
	@$(MAKE) -C $(LIB)/libft

$(AR_LIB_DBG):
	@$(MAKE) debug -C $(LIB)/libft

$(DIR_OBJS):
	@mkdir -p $(DIR_OBJS)

.PHONY: all clean fclean re header debug compile

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
