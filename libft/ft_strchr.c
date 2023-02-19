/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:45:59 by youngjki          #+#    #+#             */
/*   Updated: 2023/01/03 22:46:10 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	w;

	w = (unsigned char)c;
	if (w == 0)
		return ((char *)s + ft_strlen((char *)s));
	while (*s)
	{
		if (*s == w)
		{
			return ((char *)s);
		}
		s++;
	}
	return (0);
}
