/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichew <jichew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:43:21 by jichew            #+#    #+#             */
/*   Updated: 2023/06/02 18:31:39 by jichew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next(char *str)
{
	int i;
	
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

	
}

char	*get_next_line(int fd)
{
	char	*ln;
	char	*hold_ln;
	int		i;

	if (fd < 0)
		return (NULL);
	ln = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!ln)
		return (NULL);
	ln[BUFFER_SIZE + 1] = '\0';
	while (1)
	{
		if (read (fd, ln, BUFFER_SIZE) <= 0)
			return (NULL);
		hold_ln = gnl_strjoin(hold_ln, ln);
		if (get_next(ln))
			break ;

	}
}

int	main(void)
{
	int	fd1;
	char*	str1;
	int	i;

	i = 0;
	fd1 = open("a.txt", O_RDONLY);
	while(i < 3)
	{
		str1 = calloc(9, sizeof(char));
		read(fd1, str1, 8);
		printf("str1 = %s\n", str1);
		free(str1);
		++i;
	}
	return (0);
	
}