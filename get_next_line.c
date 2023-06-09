/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichew <jichew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:43:21 by jichew            #+#    #+#             */
/*   Updated: 2023/06/09 21:41:53 by jichew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_substr(char	*s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	// if (!s)
	// 	return (NULL);
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		substr[i++] = s[start++];
	substr[i] = 0;
	return (substr);
}

int	get_next(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (j);
		j++;
		i++;
	}
	return (-1);
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
		mal_size = (ft_gnlstrlen(str1) + ft_gnlstrlen(str2) + 1);
	tmp = malloc(mal_size * sizeof(char));
	if (!tmp)
		return (NULL);
	if (str1)
	{
		count_1 = -1;
		while (str1[++count_1])
			tmp[count_1] = str1[count_1];
		free(str1);
	}
	count_2 = -1;
	while (str2[++count_2])
		tmp[count_1++] = str2[count_2];
	tmp[count_1] = 0;
	
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
	final_o = ft_substr(hold_ln, 0, get_next(hold_ln));
	hold_ln = 
	return (final_o);
}

int	main(void)
{
	read()
}