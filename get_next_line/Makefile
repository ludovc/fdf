SRCS		= get_next_line.c get_next_line_utils.c
SRCS_B		= get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS		= $(SRCS:.c=.o)
OBJS_B		= $(SRCS_B:.c=.o)

NAME		= get_next_line.a

CFLAGS		= -Wall -Wextra -Werror -g

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rcs -o $(NAME) $(OBJS)

all:		$(NAME)

bonus:		$(OBJS_B)
			ar rcs -o $(NAME) $(OBJS_B)

clean:
			rm -f $(OBJS) $(OBJS_B)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
