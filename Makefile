CC = cc

NAME = libftprintf.a

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror

OPTION = -c

SRC = 	ft_printf.c ft_put_base_nbr.c

OBJ = $(SRC:.c=.o)

all: ${NAME}

$(NAME): ${OBJ}
	ar rcs $(NAME) $(OBJ)

%.o: %.c ${HEADER}
	${CC} ${FLAGS} -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

