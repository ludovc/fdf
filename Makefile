SRCS = \
fdf.c \

NAME =		a.out
CFLAGS =	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	minilibx-linux/libmlx.a $(SRCS)
			cc $(CFLAGS) $(SRCS) -o $(NAME)

minilibx-linux/libmlx.a:
			git clone https://github.com/42Paris/minilibx-linux.git
			make -C minilibx-linux
