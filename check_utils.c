/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhazzout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:33:40 by bhazzout          #+#    #+#             */
/*   Updated: 2023/01/04 02:43:56 by bhazzout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *av)
{
	int		len;
	int		i;
	char	*str;

	len = ft_strlen(av);
	str = malloc (len + 1);
	i = 0;
	while (av[i])
	{
		str[i] = av[i];
		i++; 
	}
	str[i] = '\0';
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	len;
	char	*ptr;

	if (size && count > SIZE_MAX / size)
		return (0);
	len = count * size;
	ptr = (char *)malloc(len);
	if (!ptr)
		return (0);
	ft_bzero (ptr, len);
	return (ptr);
}

int	*ft_memcpy(int *dest, int *src, size_t n)
{
	size_t			i;

	if (src == dest)
		return (dest);
	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
