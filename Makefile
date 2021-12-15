# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 14:42:09 by bguyot            #+#    #+#              #
#    Updated: 2021/12/15 14:36:08 by bguyot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_of_life

SRCS = srcs/*.c

OBJS = $(SRCS:.c=.o)

LIBS = -lft

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRCS)
	mv *.o srcs
	gcc $(FLAG) -L. $(LIBS) -o $(NAME) $(OBJS)

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
