/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:52:46 by youngjki          #+#    #+#             */
/*   Updated: 2022/08/31 18:28:07 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (*src)
	{
		if (j < nb)
		{
			dest[i] = *src++;
			i++;
			j++;
		}
		else
			src++;
	}
	dest[i] = '\0';
	return (dest);
}
