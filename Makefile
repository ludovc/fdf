SRCS = \
fdf.c \
parsing.c \

NAME =		fdf
CFLAGS =	-Wall -Wextra -Werror -g
LIBFT =		libft/libft.a

all:		$(NAME)

parsing:
	cc -g parsing.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/libft.a

$(NAME):	minilibx-linux/libmlx.a $(LIBFT) $(SRCS)
			cc $(CFLAGS) $(SRCS) get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/libft.a -Lminilibx-linux -lmlx -lXext -lX11 -o $(NAME) -lm

$(LIBFT):
	make -C libft

minilibx-linux/libmlx.a:
			git clone https://github.com/42Paris/minilibx-linux.git
			make -C minilibx-linux

fclean:
			rm -f $(NAME)

re:	fclean all
