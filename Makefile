NAME = libft.a
CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

SRC = part1/ft_atoi.c \
	part1/ft_bzero.c \
	part1/ft_calloc.c \
	part1/ft_isalnum.c \
	part1/ft_isalpha.c \
	part1/ft_isascii.c \
	part1/ft_isdigit.c \
	part1/ft_isprint.c \
	part1/ft_memchr.c \
	part1/ft_memcmp.c \
	part1/ft_memcpy.c \
	part1/ft_memmove.c \
	part1/ft_memset.c \
	part1/ft_strchr.c \
	part1/ft_strdup.c \
	part1/ft_strlcat.c \
	part1/ft_strlcpy.c \
	part1/ft_strlen.c \
	part1/ft_strncmp.c \
	part1/ft_strnstr.c \
	part1/ft_strrchr.c \
	part1/ft_tolower.c \
	part1/ft_toupper.c \
	part2/ft_itoa.c \
	part2/ft_putchar_fd.c \
	part2/ft_putendl_fd.c \
	part2/ft_putnbr_fd.c \
	part2/ft_putstr_fd.c \
	part2/ft_split.c \
	part2/ft_striteri.c \
	part2/ft_strjoin.c \
	part2/ft_strmapi.c \
	part2/ft_strtrim.c \
	part2/ft_substr.c \
	part3/ft_lstadd_back.c \
	part3/ft_lstadd_front.c \
	part3/ft_lstclear.c \
	part3/ft_lstdelone.c \
	part3/ft_lstiter.c \
	part3/ft_lstlast.c \
	part3/ft_lstmap.c \
	part3/ft_lstnew.c \
	part3/ft_lstsize.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
