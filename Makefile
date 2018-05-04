# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ardurand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 17:57:47 by ardurand          #+#    #+#              #
#    Updated: 2017/10/24 17:57:48 by ardurand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=		main.c \
				fonctiontab.c \
				utilitaire.c \
				parser.c \
				findcost.c \

OBJ		=		$(SRC:.c=.o)

LIB		=		libft/libft.a

INC		=		libft/includes

NAME	=		ardurand.filler

RM		=		rm -f

FLAG	=		-Wall -Werror -Wextra

all: libft.a $(NAME)

$(NAME): $(OBJ)
		gcc -g $(FLAG) -c $(SRC)  -I $(INC)
		gcc -o $(NAME) $(OBJ) -L. $(LIB) -g

libft.a:
		make -C libft/

re:		fclean all

clean:
		@$(RM) $(OBJ)
		make -C libft/ clean

fclean:
		@$(RM) $(OBJ) $(NAME)
		make -C libft/ fclean
		@$(RM) libft.h.gch

.PHONY: clean fclean re
