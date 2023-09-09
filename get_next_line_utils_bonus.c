/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:29:22 by fdundar           #+#    #+#             */
/*   Updated: 2023/07/15 09:29:48 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
