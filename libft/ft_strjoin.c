/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:28:53 by youngjki          #+#    #+#             */
/*   Updated: 2023/01/12 15:29:12 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned char	*result;
	int				s1_len;
	int				s2_len;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1))
		return (ft_strdup(s2));
	else if (!(s2))
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (unsigned char *)malloc(sizeof(unsigned char) * \
	(s1_len + s2_len + 1));
	if (!result)
		return ((char *)result);
	ft_strlcpy((char *)result, s1, s1_len + 1);
	ft_strlcat((char *)result + s1_len, s2, s2_len + 1);
	return ((char *)result);
}
