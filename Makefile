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

NAME 			=	fdf
NAME_DBG 		=	fdf_d

LIB_DIR			=	lib
LIBFDF			=	libfdf
MINILIBX		=	mlx

# Config
# ****************************************************************************

CC 				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -O2 $(DBGFLAGS) $(INCLUDE)
# DBGFLAGS		=	-g3 -fsanitize=address
LIBFDFFLAGS		=	-L $(LIB_DIR)/$(LIBFDF) -lfdf
LIBFDFFLAGSD	=	-L $(LIB_DIR)/$(LIBFDF) -lfdf_d

OS				=	$(shell uname -s)
ifeq ($(OS), Linux)
	MLXFLAGS	=	-L /usr/local/lib -lmlx_Linux -L/usr/X11/lib -I/usr/local/include -lXext -lX11 -lm -lz
	INCLUDE		=	-I $(LIBFDF)/includes -I includes
else
	MLXFLAGS	=	-L $(LIB_DIR)/mlx -lmlx -framework OpenGL -framework AppKit
	INCLUDE		=	-I $(LIB_DIR)/$(LIBFDF)/includes -I $(LIB_DIR)/mlx -I includes
endif

DEPS			=	includes/fdf.h $(LIB_DIR)/$(LIBFDF)/includes/libfdf.h $(LIB_DIR)/mlx/mlx.h

MLXLIB			=	$(LIB_DIR)/$(MINILIBX).a

AR_LIB			=	$(LIB_DIR)/$(LIBFDF)/$(LIBFDF).a
AR_LIB_DBG		=	$(LIB_DIR)/$(LIBFDF)/$(LIBFDF)_d.a

# Source files
# ****************************************************************************

DIR_SRCS		=	src
SRCSFILE		=	main.c colors.c init.c draw.c draw_line.c draw_circle.c		\
					utils.c	hooks.c	map_parsing.c projection.c world_matrix.c	\
					rotation_matrix.c strtrim.c

SRCS			=	$(addprefix $(DIR_SRCS)/, $(SRCSFILE))

DIR_OBJS		=	obj
OBJS			=	$(addprefix $(DIR_OBJS)/, $(notdir $(SRCS:.c=.o)))

# Recipe
# ****************************************************************************

all: header compile

$(DIR_OBJS)/%.o:	$(DIR_SRCS)/%.c $(DEPS) | $(DIR_OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

$(NAME): $(OBJS) $(AR_LIB) $(MLXLIB)
	@printf "$(_BLUE)\nCompiled source files\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFDFFLAGS) $(MLXFLAGS) -o $@
	@printf "$(_GREEN)Finish compiling $(NAME)!$(_END)\n"

$(NAME_DBG): $(OBJS) $(AR_LIB_DBG) $(MLXLIB)
	@printf "$(_BLUE)\nCompiled source files\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFDFFLAGSD) $(MLXFLAGS) -o $@
	@printf "$(_GREEN)Finish compiling $(NAME)!$(_END)\n"

compile:
	@$(MAKE) $(NAME) -C .

bonus: all

debug: header
	@$(MAKE) $(NAME_DBG) -C .

clean:	header
	@printf "$(_YELLOW)Removing object files ...$(_END)\n"
	@make clean -C $(LIB_DIR)/$(MINILIBX)
	@make clean -C $(LIB_DIR)/$(LIBFDF)
	@rm -rf $(DIR_OBJS) $(DIR_OBJSD)
	@rm -fr *.dSYM

fclean:	clean
	@printf "$(_RED)Removing Executable ...$(_END)\n"
	@make fclean -C $(LIB_DIR)/$(LIBFDF)
	@rm -rf $(NAME) $(NAME_DBG)

re:		header fclean all

$(MLXLIB):
	@$(MAKE) -C $(LIB_DIR)/$(MINILIBX)

$(AR_LIB):
	@$(MAKE) -C $(LIB_DIR)/$(LIBFDF)

$(AR_LIB_DBG):
	@$(MAKE) debug -C $(LIB_DIR)/$(LIBFDF)

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
