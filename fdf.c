#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		byte_per_pixel;
	int		vertical_offset;
	int		horizontal_offset;

	byte_per_pixel = data->bits_per_pixel / 8;
	vertical_offset = y * data->line_length;
	horizontal_offset = x * byte_per_pixel;
	dst = data->addr + (vertical_offset + horizontal_offset);
	*(unsigned int*)dst = color;
}

void	put_horizontal_line(t_data *img, int x, int y, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		my_mlx_pixel_put(img, x + i, y, 0x00FFFFFF);
		i++;
	}
}

void	put_vertical_line(t_data *img, int x, int y, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		my_mlx_pixel_put(img, x, y + i, 0x00FFFFFF);
		i++;
	}
}

void	create_image(t_mat *mat, t_data *img)
{
	int		i;
	int		j;

	i = 0;
	while (mat->mat[i])
	{
		j = 0;
		while (j < mat->x)
		{
			my_mlx_pixel_put(img, 100 + j * 30, 100 + i * 30 + j * 10, 0x00FFFFFF);
			j++;
		}
		i++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_mat	mat;

	parsing(&mat);
	print_mat(mat);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	create_image(&mat, &img);


	//put_horizontal_line(&img, 0, 0, 100);
	//put_vertical_line(&img, 10, 10, 100);
	//put_horizontal_line(&img, 10, 110, 100);
	//put_vertical_line(&img, 110, 10, 100);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
