#include "get_next_line.h"

size_t ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, char *src, size_t dsize)
{
	size_t	i;
	size_t	slen;

	slen = ft_strlen(src);
	if (dsize == 0)
		return (slen);
	i = 0;
	while (src[i] && (i < (dsize - 1)))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (slen);
}

int	has_newline(char *bigline)
{
	int	i;

	i = 0;
	while (bigline[i])
	{
		if (bigline[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}