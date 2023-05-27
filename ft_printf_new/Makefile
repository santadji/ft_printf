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

SRCS =		parsing.c\
			ft_printf.c\
			convert.c\

OBJS =		$(SRCS:.c=.o)
INCLUDES =	ft_printf.h
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.o.c: $(SRCS)
	@gcc -c $(CFLAGS) -I $(INCLUDES) $^ -o $(^:.c=.o)

$(NAME): $(OBJS)
	@(ar	rc $(NAME) $(OBJS) $(LIB_OBJS))
	@echo "ft_printf compiled"

clean:
	@(rm -f $(OBJS))
	@echo "ft_print cleaned"

fclean: cleanlib clean
	@(rm -f a.out)
	@(rm -rf a.out.dSYM)
	@(rm -rf $(NAME))
	@echo "ft_printf full cleaned"

re : fclean all
