# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: santadji <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 15:53:49 by santadji          #+#    #+#              #
#    Updated: 2023/05/27 16:38:47 by santadji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	./ft_atoi.c\
		./ft_bzero.c\
		./ft_calloc.c\
		./ft_isalnum.c\
		./ft_isalpha.c\
		./ft_isascii.c\
		./ft_isdigit.c\
		./ft_isprint.c\
		./ft_itoa.c\
		./ft_itoa_base.c\
		./ft_memchr.c\
		./ft_memcmp.c\
		./ft_memcpy.c\
		./ft_memmove.c\
		./ft_memset.c\
		./ft_putchar_fd.c\
		./ft_putendl_fd.c\
		./ft_putnbr_fd.c\
		./ft_putstr_fd.c\
		./ft_split.c\
		./ft_strchr.c\
		./ft_strdup.c\
		./ft_striteri.c\
		./ft_strjoin.c\
		./ft_strlcat.c\
		./ft_strlcpy.c\
		./ft_strlen.c\
		./ft_strmapi.c\
		./ft_strncmp.c\
		./ft_strnstr.c\
		./ft_strrchr.c\
		./ft_strtrim.c\
		./ft_substr.c\
		./ft_tolower.c\
		./ft_toupper.c\

BONUS_SRCS =	./ft_lstnew.c\
				./ft_lstadd_front.c\
				./ft_lstsize.c\
				./ft_lstlast.c\
				./ft_lstadd_back.c\
				./ft_lstdelone.c\
				./ft_lstclear.c\
				./ft_lstiter.c\
				./ft_lstmap.c\

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
INCLUDES = libft.h
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o%.c: $(SRCS) $(BONUS_SRCS)
		gcc -c $(CFLAGS) -I $(INCLUDES) $^ -o $(^:.c=.o)

$(NAME): $(OBJS)
		ar	-rc $(NAME) $(OBJS)

bonus : $(NAME) $(BONUS_OBJS)
	ar -rcs $(NAME) $(BONUS_OBJS)

clean :
		rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all
