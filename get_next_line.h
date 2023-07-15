/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdundar <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:30:37 by fdundar           #+#    #+#             */
/*   Updated: 2023/07/15 09:30:38 by fdundar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

size_t	ft_strlcpy(char *dest, char *src, size_t dsize);
size_t	ft_strlen(char *str);
int		has_newline(char *bigline);
char	*get_next_line(int fd);

#endif
