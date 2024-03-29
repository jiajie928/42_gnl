/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichew <jichew@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:30:25 by jichew            #+#    #+#             */
/*   Updated: 2023/09/18 13:51:47 by jichew           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	8
# endif

# ifndef FILE_D_SIZE
#  define FILE_D_SIZE	8192

int		ft_strlen(char *str);
void	ft_cleanmem(char *str);
char	*ft_strdup(char *str);
char	*ft_strchr(char *s, char c);

#endif