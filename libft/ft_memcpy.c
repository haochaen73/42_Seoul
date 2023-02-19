/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:11:32 by youngjki          #+#    #+#             */
/*   Updated: 2023/01/03 22:11:36 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;
	size_t			i;

	if (!dst && !src)
		return (0);
	new_dest = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	i = 0;
	while (i++ < n)
	{
		*new_dest++ = *new_src++;
	}
	return (dst);
}
