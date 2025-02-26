#ifndef FDF_H
# define FDF_H

# include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include <unistd.h>
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "ft_printf/ft_printf.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mat
{
	int		**mat;
	int		x;
}				t_mat;

void	parsing(t_mat *mat);
void	print_mat(t_mat mat);

#endif
