SRCS = \
ft_printf.c \
ft_putnumbers.c \
ft_putchars.c \

NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)

.c.o:
	cc -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
