#include <unistd.h>

void	print_str(char **src)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (src[j] != NULL)
	{
		while (src[j][i] != '\0')
		{
			write (1, &src[j][i], 1);
			i++;
		}
		i = 0;
		j++;
		write (1, "\n", 1);
	}
}
