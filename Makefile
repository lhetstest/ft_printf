NAME = libftprintf.a

SRCS = ft_printf.c parse.c print.c utils.c

OBJS = ${SRCS:%.c=%.o}

$(NAME):
		gcc -Wall -Werror -Wextra -c $(SRCS) -I ./
		ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all
