# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/03 23:52:47 by tingo             #+#    #+#              #
#    Updated: 2018/06/24 03:29:09 by tingo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC     = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -mavx
NAME   = ft_ssl

ODIR   = obj
SDIR   = src
LDIR   = libft
IDIR   = includes

_SRC   = ssl_error01.c \
         ssl_error00.c \
         ft_ssl.c \
         help.c \
         ssl_queue.c \
         ssl_hashmap.c \
         base64/base64.c \
         base64/b64_decode.c \
         base64/b64_encode.c \
         md5/md5.c \
         md5/md5_hash.c \
         sha256/sha256_hash.c \
         sha256/sha256.c \
         ssl_utils.c
SRC    = $(patsubst %,$(SDIR)/%,$(_SRC))

_OBJ   = $(_SRC:.c=.o)
OBJ    = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: $(NAME)

$(NAME):
	@make re -C libft
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) -I $(IDIR) -L $(LDIR) -lft

clean:
	@/bin/rm -rf $(ODIR)
	@echo remove $(ODIR)

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo remove $(NAME)

re:	fclean all
