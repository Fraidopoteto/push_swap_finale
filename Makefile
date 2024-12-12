# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 14:22:55 by joschmun          #+#    #+#              #
#    Updated: 2024/12/12 13:40:10 by Furaido          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name des ausführbaren Programms
NAME = push_swap

# Compiler und Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Quell- und Objektdateien
SRCS = push_swap.c operations.c utils00.c utils01.c utils02.c main.c select_sort.c \
utils03.c
OBJS = $(SRCS:.c=.o)

# Pfad zu libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = $(LIBFT_DIR)

# Regeln
all: $(NAME)

# Erstellen des ausführbaren Programms
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft

# Kompilieren der libft, nur wenn libft.a nicht existiert
$(LIBFT):
	make -C $(LIBFT_DIR)

# Erstellen der Objektdateien
%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_INC) -c $< -o $@

# Aufräumen der Objektdateien
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

# Aufräumen der Objektdateien und der ausführbaren Datei
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# Alles neu erstellen
re: fclean all

.PHONY: all clean fclean re

