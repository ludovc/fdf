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
	while (fdf->mat.mat[i])
	{
		j = 0;
		while (j < fdf->mat.x)
		{
			my_mlx_pixel_put(img_data, j * 30, i * 30, 0x00FFFFFF);
			j++;
		}
		i++;
	}
	return (img_data);
}

void isometric(int *x, int *y, int z)
{
    int prev_x = *x;
    int prev_y = *y;
    *x = (prev_x - prev_y) * cos(0.523599); // 30°
    *y = (prev_x + prev_y) * sin(0.523599) - z;
}

void	bresenham(t_fdf *fdf, int x0, int y0, int x1, int y1)
{
	int dx = abs(x1 - x0);
	int dy = -abs(y1 - y0);
	int sx = x0 < x1 ? 1 : -1;
	int sy = y0 < y1 ? 1 : -1;
	int err = dx + dy;  // errore iniziale

	while (1)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x0, y0, color); // Disegna il pixel
		if (x0 == x1 && y0 == y1)
			break;
		int e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

int	main(void)
{
	t_fdf	*fdf;
	t_data	*img_data;

	fdf = malloc(sizeof(t_fdf));
	parsing(&fdf->mat);
	print_mat(fdf->mat);
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, 1000, 1000, "Hello world!");
	//create_inclined_image(&fdf->mat, &img);
	img_data = create_flat_image(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, img_data->img, 0, 0);

	//put_horizontal_line(&img, 0, 0, 100);
	//put_vertical_line(&img, 10, 10, 100);
	//put_horizontal_line(&img, 10, 110, 100);
	//put_vertical_line(&img, 110, 10, 100);
	mlx_hook(fdf->mlx_win, 17, 0, close_window, fdf);
	mlx_loop(fdf->mlx);
}
