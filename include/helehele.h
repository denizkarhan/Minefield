#ifndef HELEHELE_H
# define HELEHELE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

void	paste(char **map, char *buffer, int a);
void	print_str(char **src);
char	*get_instr(char *s);
int		line_len(char *s);
int		ft_strlen(char *s);

#endif
