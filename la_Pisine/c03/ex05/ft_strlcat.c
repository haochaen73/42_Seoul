/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:28:17 by youngjki          #+#    #+#             */
/*   Updated: 2022/08/31 20:57:40 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	size_dest;
	unsigned int	size_src;
	unsigned int	result;
	unsigned int	k;

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
