int	line_len(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\n')
		i++;
	i++;
	while (s[i] != '\n')
	{
		j++;
		i++;
	}
	return (j);
}
