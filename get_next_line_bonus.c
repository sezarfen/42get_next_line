// static variable üzerinden gideceğize
/*
	Bu yazilar get_next_line projesini
	anlamak ve nesıl bir yol izlendiğini
	göstermek amacıyla yazılmıştır.
*/
// verilen BUFFER_SIZE kadar okuma yapacağız
#include "get_next_line_bonus.h"

char	*go_forward(char *bigline, int i, int j)
{
	char	*newbig;

	while (bigline[i] && bigline[i] != '\n')
		i++;
	if (bigline[i] == '\0')
	{
		free(bigline);
		return (NULL); // daha ileri gitmeye gerek yok dosya bitmiş
	}
	if (bigline[i] == '\n')
		i++;
	newbig = malloc(ft_strlen(bigline) - i + 1);
	if (!newbig)
		return (NULL);
	j = 0;
	while (bigline[i + j])
	{
		newbig[j] = bigline[i + j];
		j++;
	}
	newbig[j] = '\0';
	free(bigline);
	return (newbig);
}

char	*extract_newline(char *bigline)
{
	char	*newline;
	int		i;

	if (!bigline || bigline[0] == '\0')
		return (NULL);
	i = 0;
	while (bigline[i] && bigline[i] != '\n')
		i++;
	if (bigline[i] == '\n')
		i++;
	newline = malloc(sizeof(char) * (i + 1));
	if (!newline)
		return (NULL);
	i = 0;
	while (bigline[i] && bigline[i] != '\n')
	{
		newline[i] = bigline[i];
		i++;
	}
	if (bigline[i] == '\n')
		newline[i++] = '\n';
	newline[i] = '\0';
	return (newline);
}

char	*add_to_bigline(char *bigline, char *buffer)
{
	char	*newbig;
	int		i;
	int		j;

	if (bigline == NULL)
	{
		bigline = malloc(sizeof(char) * 1);
		bigline[0] = '\0'; // bigline = NULL olarak geliyse boş olarak başlatıyoruz
	}

	if (bigline == NULL || buffer == NULL)
		return (NULL);

	newbig = malloc(ft_strlen(bigline) + ft_strlen(buffer) + 1);
	if (!newbig)
		return (NULL);

	i = 0;
	while (bigline[i])
	{
		newbig[i] = bigline[i];
		i++;
	}

	j = 0;
	while (buffer[j])
		newbig[i++] = buffer[j++];
	newbig[i] = '\0';

	free(bigline);

	return (newbig);
}

char	*get_next_line(int fd)
{
	static char	*bigline = NULL;
	
	char		*buffer;
	
	int			temp_read;

	char		*newline;  // bigline üzerinden alıp geri döndüreceğimiz eleman
	
	// buffer üzerine okumak , ve oradan bigline ' a ekleme yapmak
	
	// ta ki bigline içerisindeki string '\n' içerene kadar
	
	if (fd < 0 || BUFFER_SIZE <= 0) // fd ve BUFFER_SIZE kontrolü
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	temp_read = read(fd, buffer, BUFFER_SIZE);
	if (temp_read == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[temp_read] = '\0';
	bigline = add_to_bigline(bigline, buffer);
	free(buffer);
	if (has_newline(bigline) || temp_read == 0)
	{
		newline = extract_newline(bigline); // zaten null ataması yapıyor
		bigline = go_forward(bigline, 0, 0);
		return (newline);
	}
	else
		return (get_next_line(fd));
}