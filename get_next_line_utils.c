/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichew <jichew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:50:07 by jichew            #+#    #+#             */
/*   Updated: 2023/06/26 19:32:51 by jichew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_cleanmem(char *str)
{
	int	i;

	i = BUFFER_SIZE;
	while (i >= 0)
	{
		str[i] = 0;
		i--;
	}
}

char	*ft_strdup(char *str)
{
	char	*c;
	int		i;

	c = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		c[i] = str[i];
	c[i] = '\0';
	return (c);
}

char	*ft_strchr(char *s, char c)
{
	int		i;
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
