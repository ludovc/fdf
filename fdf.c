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

void	create_inclined_image(t_mat *mat, t_data *img)
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

typedef struct s_fdf
{
	void	*mlx;
	void	*mlx_win;
	t_mat	mat;
}	t_fdf;

int	close_window(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	mlx_destroy_window(fdf->mlx, fdf->mlx_win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free(fdf);
	exit(0);
	return (0);
}

t_data	*create_flat_image(t_fdf *fdf)
{
	int		i;
	int		j;
	t_data	*img_data;

	img_data = malloc(sizeof(t_data));
	if (!img_data)
		return (NULL);
	img_data->img = mlx_new_image(fdf->mlx, 1000, 1000);
	img_data->addr = mlx_get_data_addr(img_data->img, &img_data->bits_per_pixel, &img_data->line_length, &img_data->endian);
	i = 0;
	while (mat->mat[i])
	{
		j = 0;
		while (j < mat->x)
		{
			my_mlx_pixel_put(img_data, 100 + j * 30, 100 + i * 30 + j * 10, 0x00FFFFFF);
			j++;
		}
		i++;
	}
}

int	main(void)
{
	t_fdf	*fdf;
	t_data	*img;

	fdf = malloc(sizeof(t_fdf));
	//parsing(&fdf->mat);
	//print_mat(fdf->mat);
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, 1000, 1000, "Hello world!");
	//create_inclined_image(&fdf->mat, &img);
(void)img;

	//put_horizontal_line(&img, 0, 0, 100);
	//put_vertical_line(&img, 10, 10, 100);
	//put_horizontal_line(&img, 10, 110, 100);
	//put_vertical_line(&img, 110, 10, 100);
	//mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, img.img, 0, 0);
	mlx_hook(fdf->mlx_win, 17, 0, close_window, fdf);
	mlx_loop(fdf->mlx);
}
