/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:51:33 by youngjki          #+#    #+#             */
/*   Updated: 2023/01/03 20:51:35 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;
	size_t			i;

	if ((!dst && !src) || (dst == src))
		return (dst);
	else if (dst < src)
	{
		new_dest = (unsigned char *)dst;
		new_src = (unsigned char *)src;
		i = 0;
		while (i++ < n)
			*new_dest++ = *new_src++;
	}
	else
	{
		new_dest = (unsigned char *)dst + (n - 1);
		new_src = (unsigned char *)src + (n - 1);
		i = n;
		while (i-- > 0)
			*new_dest-- = *new_src--;
	}
	return (dst);
}
