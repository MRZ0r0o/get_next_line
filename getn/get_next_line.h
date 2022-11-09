/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 01:17:31 by mradwan           #+#    #+#             */
/*   Updated: 2022/09/23 13:48:03 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
char	*takel(char	*k);
char	*readk(int fd, char	*all);
char	*ft_strjoin(char *s1, char *s2);
char	*the_rest(char *k);
size_t	ft_strlen(const char *s);

#endif