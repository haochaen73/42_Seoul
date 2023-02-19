/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:51:42 by youngjki          #+#    #+#             */
/*   Updated: 2023/01/03 20:51:44 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	size_dest;
	size_t	size_src;
	size_t	result;
	size_t	k;

	size_dest = 0;
	size_src = 0;
	while (dest[size_dest])
		++size_dest;
	while (src[size_src])
		++size_src;
	result = size_dest + size_src;
	if (size_dest >= size)
		return (size_src + size);
	else
	{
		k = 0;
		while (size_dest < size - 1 && src[k])
			dest[size_dest++] = src[k++];
		dest[size_dest] = '\0';
	}
	return (result);
}
