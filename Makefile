# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: santadji <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 18:49:39 by santadji          #+#    #+#              #
#    Updated: 2023/05/27 19:02:32 by santadji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =		srcs/parsing.c\
			srcs/ft_printf.c\
			srcs/convert.c\

OBJS =		$(SRCS:.c=.o)
LIB_OBJS =	./libft/*.o
INCLUDES =	./include/ft_printf.h
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o%.c: $(SRCS)
	@gcc -c $(CFLAGS) -I $(INCLUDES) $^ -o $(^:.c=.o)

$(NAME): $(OBJS)
	@(make -C libft)
	@(ar	rc $(NAME) $(OBJS) $(LIB_OBJS))
	@echo "ft_printf compiled"

clean:
	@(rm -f $(OBJS))
	@(make clean -C libft)
	@echo "ft_print cleaned"

cleanlib:
	@(make fclean -C libft)

fclean: cleanlib clean
	@(rm -f libft.a)
	@(rm -f a.out)
	@(rm -rf a.out.dSYM)
	@(rm -rf $(NAME))
	@echo "ft_printf full cleaned"

re : fclean all

