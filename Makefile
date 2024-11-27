SRCS = \
fdf.c \

CFLAGS =	-Wall -Wextra -Werror

all:		a.out

a.out:		minilibx-linux/libmlx.a $(SRCS)
			cc $(CFLAGS) $(SRCS)

minilibx-linux/libmlx.a:
			git clone https://github.com/42Paris/minilibx-linux.git
			make -C minilibx-linux
