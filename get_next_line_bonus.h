#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 15
#endif

size_t	ft_strlcpy(char *dest, char *src, size_t dsize);
size_t	ft_strlen(char *str);
int		has_newline(char *bigline);
char	*get_next_line(int fd);

#endif


/*


#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd = open("text.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	return (0);
}

*/