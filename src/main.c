#include "helehele.h"

void	indexs(char **s, int x, int y, int i, int j);
void	kontrol(char **s, int x, int y, int i, int j);

int	length_k(char *str)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		total = total * 10 + (str[i] - '0');
		i++;
	}
	return (total);
}

char	**savemap(char	*txtfile)
{
	int		fd;
	char	buffer[10000];
	char	**map;
	char	*instr;
	int		i;
	int		j;
	int		k;

	j = 0;
	fd = open(txtfile, O_RDWR);
	if (fd != -1)
	{
		read(fd, buffer, sizeof(buffer));
		instr = get_instr(buffer);
		k = length_k(buffer);
		map = (char **) malloc(sizeof(char *) * (k + 1));
		i = line_len(buffer);
		while (j <= k)
		{
			map[j] = (char *)malloc(sizeof(char) * (i + 1));
			j++;
		}
		j = 0;
		while (buffer[j] != '\n')
			j++;
		j++;
		paste(map, &buffer[j], k);
		kontrol(map, k - 1, k - 1, 0, 0);
		close(fd);
		return (map);
	}
	return (0);
}

void	kontrol(char **s, int x, int y, int i, int j)
{
	int	a;
	int	b;

	a = i;
	while (a <= x)
	{
		b = j;
		while (b <= y)
		{
			if (s[a][b] == 'o')
			{
				indexs(s, x, y, i, j);
				return ;
			}
			b++;
		}
		a++;
	}
	a = i;
	while (a <= x)
	{
		b = j;
		while (b <= y)
		{
			s[a][b] = 'x';
			b++;
		}
		a++;
	}
}

void	indexs(char **s, int x, int y, int i, int j)
{
	int	k;
	int	end;

	end = ft_strlen(*s) - 1;
	k = y - j;
	if (k > -1 && x == end && y == end)
	{
		k -= 1;
		kontrol(s, k, k, 0, 0);
		return ;
	}
	else if (s[x][y + 1] == '\0')
	{
		y = k;
		x++;
		kontrol(s, x, y, x - k, 0);
		return ;
	}
	else
	{
		y += 1;
		j++;
		kontrol(s, x, y, i, j);
		return ;
	}
}

int	main(int ac, char **av)
{
	char	**arr;
	int		i;
	int		j;

	j = 0;
	i = 0;
	(void)ac;
	arr = savemap(av[1]);
	while (i < ft_strlen(arr[i]))
	{
		while (j < ft_strlen(arr[i]))
		{
			write (1, &arr[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		j = 0;
		i++;
	}
	return (0);
}
