/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:29:51 by fdundar           #+#    #+#             */
/*   Updated: 2023/07/15 10:29:52 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*go_forward(char *bigline, int i, int j)
{
	char	*newbig;

	while (bigline[i] && bigline[i] != '\n')
		i++;
	if (bigline[i] == '\0')
	{
		free(bigline);
		return (NULL);
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

char	*add_to_bigline(char *bigline, char *buffer, int i, int j)
{
	char	*newbig;

	if (bigline == NULL)
	{
		bigline = malloc(sizeof(char) * 1);
		bigline[0] = '\0';
	}
	if (bigline == NULL || buffer == NULL)
		return (NULL);
	newbig = malloc(ft_strlen(bigline) + ft_strlen(buffer) + 1);
	if (!newbig)
		return (NULL);
	while (bigline[i])
	{
		newbig[i] = bigline[i];
		i++;
	}
	while (buffer[j])
		newbig[i++] = buffer[j++];
	newbig[i] = '\0';
	free(bigline);
	return (newbig);
}

char	*get_nest(char **bigline, char *newline)
{
	newline = extract_newline(*bigline);
	*bigline = go_forward(*bigline, 0, 0);
	return (newline);
}

char	*get_next_line(int fd)
{
	static char	*bigline[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	int			temp_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp_read = read(fd, buffer, BUFFER_SIZE);
	if (temp_read == -1)
	{
		free(bigline[fd]);
		bigline[fd] = NULL;
		return (NULL);
	}
	buffer[temp_read] = '\0';
	bigline[fd] = add_to_bigline(bigline[fd], buffer, 0, 0);
	if (has_newline(bigline[fd]) || temp_read == 0)
		return (get_nest(&(bigline[fd]), buffer));
	else
		return (get_next_line(fd));
}
