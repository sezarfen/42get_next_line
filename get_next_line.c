#include "get_next_line.h"

char	*move_forward(char **bigstr)
{
	int		i;
	int		j;
	char	*newbig;

	i = 0; // we can take as parameter with function call
	while ((*bigstr)[i] && (*bigstr)[i] != '\n')
		i++;
	if ((*bigstr)[i] != '\n')
		i++;
	while ((*bigstr)[i + j])
		j++;
	newbig = malloc(sizeof(char) * (j + 1));
	j = 0;
	while ((*bigstr)[i + j])
	{
		newbig[j] = (*bigstr)[i + j];
		j++;
	}
	newbig[j] = '\0';
	free((*bigstr));
	return (newbig);
}

char	*extract_newline(char *bigstr)
{
	int		i;
	char	*newline;

	i = 0;
	while (bigstr[i] && bigstr[i] != '\n')
		i++;
	if (bigstr[i] == '\n')
		i++;
	newline = malloc(sizeof(char) * (i + 1));
	if (!newline)
		return (NULL);
	i = 0;
	while (bigstr[i] && bigstr[i] != '\n')
	{
		newline[i] = bigstr[i];
		i++;
	}
	if (bigstr[i] == '\n')
		newline[i++] = '\n';
	newline[i] = '\0';
	return (newline);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char 	*ft_strjoin(char *s1, char *s2, int i, int j) // i and j will be initialized with 0
{
	char	*old;
	char	*to_return;

	if (!s1 || !s2)
		return (NULL);
	old = s1;
	to_return = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!to_return)
		return (NULL);
	while (s1[i])
		to_return[j++] = s1[i++];
	i = 0;
	while (s2[i])
		to_return[j++] = s2[i++];
	to_return[j] = '\0';
	//free(old);
	return (to_return);
}

int	ft_indexof(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1); // c didn't occured
}

char	*get_next_line(int fd)
{
	static char	*bigstr = "\0";
	char		*temp;
	int			readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &temp, 0))
		return (NULL);
	readed = 1;
	printf("p0\n");
	while (ft_indexof(bigstr, '\n') == -1 && readed > 0)
	{
		printf("p1\n");
		temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!temp)
		{
			free(bigstr);
			return (NULL);
		}
		readed = read(fd, temp, BUFFER_SIZE);
		temp[readed] = '\0';
		printf("p2\n");
		bigstr = ft_strjoin(bigstr, temp, 0, 0);
		printf("p3\n");
		free(temp);
	}
	temp = extract_newline(bigstr);
	bigstr = move_forward(&bigstr);
	return (temp);
}

int main(void)
{
	int fd = open("text.txt", O_RDONLY);
	printf("fd -> %d\n", fd);
	char	*str = get_next_line(fd);
	printf("first line -> %s", str);
	free(str);
	return (0);
}