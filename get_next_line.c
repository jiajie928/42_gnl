/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichew <jichew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:43:21 by jichew            #+#    #+#             */
/*   Updated: 2023/06/07 18:48:12 by jichew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char *str1, char *str2)
{
	char	*tmp;
	int		count;

	if (!str1)
		return (str2);
	if (!str2)
		return (str1);

}

char	*get_next_line(int fd)
{
	char	*ln;
	static char	*hold_ln = NULL;
	int		result;

	if (fd < 0 || read(fd, 0, 0) || BUFFER_SIZE <= 0)
		return (NULL);
	ln = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!ln)
		return (NULL);
	while (1)
	{
		ft_cleanmem(ln);
		result = read (fd, ln, BUFFER_SIZE);
		if (result < 0)
			return (NULL);
		hold_ln = gnl_strjoin(hold_ln, ln);
		if (get_next(ln) || result == 0)
			break ;
	}
	free (ln);
}
