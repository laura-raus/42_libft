# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laraus <laraus@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/06 16:02:55 by laraus            #+#    #+#              #
#    Updated: 2026/05/09 12:01:40 by laraus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -Iincludes

LIBC_DIR = srcs/libc/
ADD_DIR = srcs/additional/
LIST_DIR = srcs/lists/

LIBC = \
	$(LIBC_DIR)ft_isalpha.c \
	$(LIBC_DIR)ft_isdigit.c \
	$(LIBC_DIR)ft_isalnum.c \
	$(LIBC_DIR)ft_isascii.c \
	$(LIBC_DIR)ft_isprint.c \
	$(LIBC_DIR)ft_strlen.c \
	$(LIBC_DIR)ft_memset.c \
	$(LIBC_DIR)ft_bzero.c \
	$(LIBC_DIR)ft_memcpy.c \
	$(LIBC_DIR)ft_memmove.c \
	$(LIBC_DIR)ft_strlcpy.c \
	$(LIBC_DIR)ft_strlcat.c \
	$(LIBC_DIR)ft_toupper.c \
	$(LIBC_DIR)ft_tolower.c \
	$(LIBC_DIR)ft_strchr.c \
	$(LIBC_DIR)ft_strrchr.c \
	$(LIBC_DIR)ft_strncmp.c \
	$(LIBC_DIR)ft_memchr.c \
	$(LIBC_DIR)ft_memcmp.c \
	$(LIBC_DIR)ft_strnstr.c \
	$(LIBC_DIR)ft_atoi.c \
	$(LIBC_DIR)ft_calloc.c \
	$(LIBC_DIR)ft_strdup.c

ADDITIONAL = \
	$(ADD_DIR)ft_substr.c \
	$(ADD_DIR)ft_strjoin.c \
	$(ADD_DIR)ft_strtrim.c \
	$(ADD_DIR)ft_split.c \
	$(ADD_DIR)ft_itoa.c \
	$(ADD_DIR)ft_strmapi.c \
	$(ADD_DIR)ft_striteri.c \
	$(ADD_DIR)ft_putchar_fd.c \
	$(ADD_DIR)ft_putstr_fd.c \
	$(ADD_DIR)ft_putendl_fd.c \
	$(ADD_DIR)ft_putnbr_fd.c

LISTS = \
	$(LIST_DIR)ft_lstnew.c \
	$(LIST_DIR)ft_lstadd_front.c \
	$(LIST_DIR)ft_lstsize.c \
	$(LIST_DIR)ft_lstlast.c \
	$(LIST_DIR)ft_lstadd_back.c \
	$(LIST_DIR)ft_lstdelone.c \
	$(LIST_DIR)ft_lstclear.c \
	$(LIST_DIR)ft_lstiter.c \
	$(LIST_DIR)ft_lstmap.c

SRCS = $(LIBC) $(ADDITIONAL) $(LISTS)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c includes/libft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

clean_tests:
	rm -f test_libc test_additional test_lists

fclean: clean clean_tests
	rm -f $(NAME)

re: fclean all

# ------------------------------------------------ #
# Extra testing targets (not part of the subject)  #
# Convenience helpers for local testing/debugging  #
# ------------------------------------------------ #

test_libc: $(NAME)
	$(CC) $(CFLAGS) tests/main_libc.c $(NAME) $(INCLUDES) -o test_libc
	./test_libc

test_additional: $(NAME)
	$(CC) $(CFLAGS) tests/main_additional.c $(NAME) $(INCLUDES) -o test_additional
	./test_additional

test_lists: $(NAME)
	$(CC) $(CFLAGS) tests/main_lists.c $(NAME) $(INCLUDES) -o test_lists
	./test_lists

valgrind_libc: test_libc
	valgrind --leak-check=full ./test_libc

valgrind_additional: test_additional
	valgrind --leak-check=full ./test_additional

valgrind_lists: test_lists
	valgrind --leak-check=full ./test_lists

.PHONY: all clean clean_tests fclean re \
	test_libc test_additional test_lists \
	valgrind_libc valgrind_additional valgrind_lists
