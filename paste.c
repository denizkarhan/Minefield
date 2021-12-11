void	paste(char **map, char *buffer, int a)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = 0;
	while (i < a)
	{
		while (buffer[j] != '\n' && buffer[j] != '\0')
		{
			map[i][k] = buffer[j];
			j++;
			k++;
		}
		if (buffer[j] != '\0')
			j++;
		k = 0;
		i++;
	}
}
