NAME =		libft.a
CC =		cc
CFLAGS =	-Wall -Wextra -Werror -g3 #-fsanitize=address

SRC =

BONUS =

OBJ =		$(SRC:.c=.o)
OBJ_BONUS = 	$(BONUS:.c=.o)

$(OBJ):		%.o: %.c
		$(CC) $(CFLAGS) 
		

$(NAME):	all

all:

clean:
		rm -f *.o

fclean:		clean
		rm -f libft

re:		fclean all

.phony: $(NAME) all clean fclean re
