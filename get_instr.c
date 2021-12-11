#include <stdlib.h>

char	*get_instr(char *s)
{
	int		i;
	char	*instr;

	i = 0;
	while (s[i] != '\n')
		i++;
	instr = (char *) malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] != '\n')
	{
		instr[i] = s[i];
		i++;
	}
	return (instr);
}
