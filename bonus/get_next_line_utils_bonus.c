/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:35:02 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/21 01:22:20 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strdup(char *s)
{
	int		i;
	char	*str;

	str = malloc (ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	s1_size;
	size_t	s2_size;
	char	*str;

	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	str = (char *)malloc (s1_size + s2_size + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < s1_size)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_size)
		str[i++] = s2[j++];
	str[i] = '\0';
	if ((char *)s1)
		free ((char *)s1);
	return (str);
}
