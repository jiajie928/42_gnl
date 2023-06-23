/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichew <jichew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:43:21 by jichew            #+#    #+#             */
/*   Updated: 2023/06/23 17:42:57 by jichew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char str, char n)
{
	char	*c;
	int		i;

	c = (char *)malloc((ft_strlen(str)) + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		c[i] = str[i];
	c[i] = '\0';
	return (c);
}

int	ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_cleanmem(char *str) //insert the str with '\0'
{
	int	i;

	i = BUFFER_SIZE;
	while (i >= 0 )
	{
		str[i] = 0;
		i--;
	}
}

char	*ft_strchr(char *s, char c)
{
	size_t	i;
	char	*src;

	src = (char *)s;
	i = 0;
	while (i <= ft_strlen(src))
	{
		if ((char)c == src[i])
			return (src + i);
		i++;
	}
	return (NULL);
}

char	*gnl_strjoin(char *str1, char *str2)
{
	char	*tmp;
	int		mal_size;
	int		count_1;
	int		count_2;

	if (!str1)
		mal_size = (ft_strlen(str2) + 1 * sizeof(char));
	else
		mal_size = (ft_strlen(str1) + ft_strlen(str2) + 1);
	tmp = malloc(mal_size * sizeof(char));
	if (!tmp)
		return (NULL);
	if (str1)
	{
		count_1 = -1;
		while (str1[++count_1])
			tmp[count_1] = str1[count_1];
		free(str1); //free hold line, hold line is a malloc
	}
	count_2 = -1;
	while (str2[++count_2])
		tmp[count_1++] = str2[count_2];
	tmp[count_1] = 0;
	return (tmp);
}

char	*get_next_line(int fd)
{
	char	*ln;
	static char	*hold_ln = NULL;
	int		result;
	char	*final_o;

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
		if (ft_strchr(ln, '\n') != NULL || result == 0)
			break ;
	}
	free (ln);
	final_o = 
	hold_ln = 
	return (final_o);
}
