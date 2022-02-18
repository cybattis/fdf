# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/21 16:51:12 by cybattis          #+#    #+#              #
#    Updated: 2022/02/16 12:29:55 by cybattis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libfdf.a
NAMED		=	libfdf_d.a

# Config
# ****************************************************************************

SHELL		=	/bin/bash
CC			=	gcc

DEPS		=	includes/libfdf.h src/printf/ft_printf.h
INCS		=	-I includes -I src/printf

CFLAGS		=	-Wall -Wextra -O2 $(INCS)
DBFLAGS		=	$(CFLAGS) -g3 -fsanitize=address

# Source files
# ****************************************************************************

SRCDIR		=	src

#Math
MATHDIR		=	$(SRCDIR)/math/
MATH		=	math.c vec2_init.c vec2_add.c vec2_mult.c vec2_div.c vec2_norm.c 	\
				vec3_init.c vec3_add.c vec3_mult.c vec3_div.c vec3_norm.c			\
				vec3_lerpf.c matrix_mult.c

#Printf
PRINTFDIR	=	$(SRCDIR)/printf
PRINTF		=	ft_printf.c conv_func.c conv_func2.c get_flags.c print_flags.c 		\
				print_flags2.c utils.c

LST_SRCS	=	ft_calloc.c ft_split.c ft_memset.c ft_strichr.c	ft_strlcat.c		\
				ft_putchar_fd.c ft_putstr_fd.c ft_putnbr.c ft_putstr.c ft_putchar.c \
				ft_strlen.c mem_utils.c ft_atoi.c ft_isspace.c ft_atoi_base.c		\
				ft_strtolower.c ft_strlcpy.c ft_get_next_line.c ft_memcpy.c			\
				ft_memmove.c ft_nbrlen.c ft_isdigit.c

SRCS		=	$(addprefix $(MATHDIR), $(MATH))		\
				$(addprefix $(SRCDIR)/, $(LST_SRCS))	\
				$(addprefix $(PRINTFDIR)/, $(PRINTF))

OBJSDIR		=	obj
OBJS		=	$(addprefix $(OBJSDIR)/, $(notdir $(SRCS:.c=.o)))

OBJSDIRD	=	objd
OBJSD		=	$(addprefix $(OBJSDIRD)/, $(notdir $(SRCS:.c=.o)))

# Recipe
# ==============================

all: 		$(NAME)

$(OBJSDIR)/%.o:	$(SRCDIR)/%.c $(DEPS) | $(OBJSDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

$(OBJSDIR)/%.o:	$(SRCDIR)/*/%.c $(DEPS) | $(OBJSDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

$(NAME):	$(OBJS)
	@printf "$(_END)\nCompiled source files\n"
	@ar rcs $(NAME) $(OBJS)
	@printf "$(_GREEN)Finish compiling $(NAME)!$(_END)\n"

# Debug
$(OBJSDIRD)/%.o:	$(SRCDIR)/%.c $(DEPS) | $(OBJSDIRD)
	@mkdir -p $(OBJSDIRD)
	@$(CC) $(DBFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

$(OBJSDIRD)/%.o:	$(SRCDIR)/*/%.c $(DEPS) | $(OBJSDIRD)
	@$(CC) $(DBFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

$(NAMED):	$(OBJSD)
	@printf "$(_END)\nCompiled debug source files\n"
	@rm -f $(NAMED)
	@ar -rcs $(NAMED) $(OBJSD)
	@printf "$(_GREEN)Finish compiling in debug mode$(NAMED)!$(_END)\n"

#Action
# ===============================

clean:
	@printf "$(_YELLOW)Removing object files ...$(_END)\n"
	@rm -rf $(OBJSDIR) $(OBJSDIRD)
	@rm -fr *.dSYM

fclean:		clean
	@printf "$(_RED)Removing Executable ...$(_END)\n"
	@rm -rf $(NAME) $(NAMED)

re:			fclean all

debug:		$(NAMED)

$(OBJSDIR):
	@mkdir -p $(OBJSDIR)

$(OBJSDIRD):
	@mkdir -p $(OBJSDIRD)

print-%:	; @echo $* = $($*)

.PHONY: all clean fclean re debug libfdf

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
