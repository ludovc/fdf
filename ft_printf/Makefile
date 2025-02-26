SRCS		= ft_printf.c ft_printf_chars.c ft_printf_numbers.c

OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a

CFLAGS		= -Wall -Wextra -Werror

.c.o:
		cc $(CFLAGS) -c -I. $< -o $@ #$(<:.c=.o)

$(NAME):	$(OBJS)
		ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
