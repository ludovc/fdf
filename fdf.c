#include <unistd.h>

void	print(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		main()
{
	print("fdf\n");
}
