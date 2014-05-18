#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhasni <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/29 12:51:34 by hhasni            #+#    #+#              #
#    Updated: 2014/04/27 19:56:27 by hhasni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fdf

CPATH =		./srcs/

HPATH =		-I ./includes/

SRCS =		main.c \
			ft_atoi.c \
			ft_bressen.c \
			ft_draw.c \
			ft_fill.c \
			ft_hook.c \
			ft_init.c \
			ft_iso.c \
			ft_joint.c \
			ft_strsplit.c \
			ft_tools.c \
			get_next_line.c

OBJS =		$(SRCS:.c=.o)

CC =		clang

CFLAGS =	-Wall -Wextra -Werror

MLXFLAGS=	-L/usr/X11/lib -lmlx -lXext -lX11

RM =		rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "\n\r\033[38;5;11m⌛  MAKE $(NAME) plz wait...\033[0m\033[K"
			@$(CC) -o $(NAME) $(MLXFLAGS) $(CFLAGS) $(OBJS)
			@echo -en "\r\033[38;5;22m✅  MAKE $(NAME)\033[0m\033[K"
			@echo "💟"

%.o:		$(CPATH)%.c
			@$(CC) -c $< $(CFLAGS) $(HPATH)

clean:
			@$(RM) $(OBJS)
			@echo -en "\r\033[38;5;124m❌  CLEAN $(NAME) \033[0m\033[K"

fclean:		clean
			@$(RM) $(NAME)
			@echo -en "\r\033[38;5;124m❌  FCLEAN $(NAME) \033[0m\033[K"

re:			fclean all
