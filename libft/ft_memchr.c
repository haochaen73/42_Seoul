/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:07:37 by youngjki          #+#    #+#             */
/*   Updated: 2023/01/05 16:07:39 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new_s;
	unsigned char	new_c;
	size_t			i;

	new_s = (unsigned char *)s;
	new_c = (unsigned char)c;
	i = 0;
	while (i++ < n)
	{
		if (*new_s == new_c)
		{
			return ((void *)new_s);
		}
		new_s++;
	}
	return (0);
}
