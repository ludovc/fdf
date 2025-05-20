SRCS = \
fdf.c \
parsing.c \

NAME =		fdf
CFLAGS =	-Wall -Wextra -Werror -g
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

.c.o:
	cc $(CFLAGS) -c $< -o $@

all:		$(NAME)

parsing:
	cc -g parsing.c libft/libft.a

$(NAME):	$(LIBFT) minilibx-linux/libmlx.a $(OBJS)
			cc $(CFLAGS) $(OBJS) libft/libft.a -Lminilibx-linux -lmlx -lXext -lX11 -o $(NAME)

$(LIBFT):
	make -C libft

minilibx-linux/libmlx.a:
			git clone https://github.com/42Paris/minilibx-linux.git
			make -C minilibx-linux

clean:
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re:	fclean all
