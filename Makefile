# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/09 08:30:56 by laskolin          #+#    #+#              #
#    Updated: 2020/07/16 16:47:59 by laskolin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME2 = checker

SRC = push_swap.c solve_small.c push_from_a.c push_to_b.c

SRC2 = checker.c checker_mover.c

SHARED = moves.c mover.c shared.c

OBJ = $(subst .c,.o,$(SRC))

OBJ2 = $(subst .c,.o,$(SRC2))

OBJSHARED = $(subst .c,.o,$(SHARED))

REST = -L./libft -lft

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME) $(NAME2)

$(NAME):
	make -C libft/
	gcc $(FLAGS) -I libft/ -c $(SRC) $(SHARED)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(OBJSHARED) $(REST)

$(NAME2):
	gcc $(FLAGS) -I libft/ -c $(SRC2) $(SHARED)
	gcc $(FLAGS) -o $(NAME2) $(OBJ2) $(OBJSHARED) $(REST)
	
clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(OBJ2)
	/bin/rm -f $(OBJSHARED)
	make clean -C libft/

fclean: clean
	make fclean -C libft/
	/bin/rm -f $(NAME)
	/bin/rm -f $(NAME2)

re: fclean all
