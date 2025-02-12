SRCS = \
fdf.c \
parsing.c \

NAME =		fdf
CFLAGS =	-Wall -Wextra -Werror -g

all:		$(NAME)

parsing:
	cc -g parsing.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/libft.a

$(NAME):	minilibx-linux/libmlx.a $(SRCS)
			cc $(CFLAGS) $(SRCS) get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/libft.a -Lminilibx-linux -lmlx -lXext -lX11 -o $(NAME) -lm

minilibx-linux/libmlx.a:
			git clone https://github.com/42Paris/minilibx-linux.git
			make -C minilibx-linux

fclean:
			rm -f $(NAME)

re:	fclean all
