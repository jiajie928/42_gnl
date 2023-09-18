/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichew <jichew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:43:21 by jichew            #+#    #+#             */
/*   Updated: 2023/09/18 13:55:24 by jichew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_strjoin(char *str1, char *str2)
{
	char	*tmp;
	int		mal_size;
	int		count_1;
	int		count_2;

	if (!str1)
		mal_size = (ft_strlen(str2) + 1);
	else
		mal_size = (ft_strlen(str1) + ft_strlen(str2) + 1);
	tmp = malloc(mal_size * sizeof(char));
	if (!tmp)
		return (NULL);
	count_1 = 0;
	count_2 = 0;
	if (str1)
	{
		while (str1[count_1])
			tmp[count_1++] = str1[count_2++];
		free(str1);
	}
	count_2 = -1;
	while (str2[++count_2])
		tmp[count_1++] = str2[count_2];
	tmp[count_1] = 0;
	return (tmp);
}

char	*ft_copy_n(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!*str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		++i;
	if (str[i] == '\n')
		++i;
	tmp = (char *) malloc (sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	tmp[i--] = '\0';
	if (i >= 0 && str[i] == '\n')
		tmp[i--] = '\n';
	while (i >= 0)
	{
		tmp[i] = str[i];
		i--;
	}
	return (tmp);
}

char	*ft_keep(char *str)
{
	char	*tmp;
// last word is '\n', nextline fisrtword is '\n' 
	if (!*str || ft_strchr(str, '\n') == NULL)
	{
		free(str);
		return (NULL);
	}
	if (!str)
		return (NULL);
	tmp = ft_strdup(ft_strchr(str, '\n') + 1);
	free (str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*ln;
	static char	*hold_ln[FILE_D_SIZE];
	int			result;
	char		*final_o;
	
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
		hold_ln[fd] = gnl_strjoin(hold_ln[fd], ln);
		if (ft_strchr(ln, '\n') != NULL || result == 0)
			break ;
	}
	final_o = ft_copy_n(hold_ln[fd]);
	hold_ln[fd] = ft_keep(hold_ln[fd]);
	free (ln);
	return (final_o);
}

int	main(void)
{
	int	fd;
	char	*str;

	fd  = open("testing.c", O_RDONLY);
	// fd = open ("a.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		printf("%s", str);
		free(str);
	}
	// system("leaks a.out");
	return (0);
}

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;

// 	fd1 = open("testing.c", O_RDONLY);
// 	fd2 = open("a.txt", O_RDONLY);
// 	fd3 = open("b.txt", O_RDONLY);
// 	i = 1;
// 	while (i <= 23)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("line [%02d]: %s\n", i, line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		printf("line [%02d]: %s\n", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }