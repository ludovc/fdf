SRCS = \
fdf.c \
parsing.c \

NAME =		fdf
CFLAGS =	-Wall -Wextra -Werror -g
OBJS = $(SRCS:.c=.o)

.c.o:
	cc $(CFLAGS) -c $< -o $@

all:		$(NAME)

parsing:
	cc -g parsing.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/libft.a

$(NAME):	minilibx-linux/libmlx.a $(OBJS)
			cc $(CFLAGS) $(OBJS) get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/libft.a -Lminilibx-linux -lmlx -lXext -lX11 -o $(NAME)

minilibx-linux/libmlx.a:
			git clone https://github.com/42Paris/minilibx-linux.git
			make -C minilibx-linux

clean:
	rm -f $(OBJS)

fclean: clean
			rm -f $(NAME)

re:	fclean all
