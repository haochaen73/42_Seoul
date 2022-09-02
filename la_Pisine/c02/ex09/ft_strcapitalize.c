/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 20:10:35 by youngjki          #+#    #+#             */
/*   Updated: 2022/08/31 14:01:07 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	str = ft_strlowcase(str);
	if (str[0] >= 97 && str[0] <= 122)
		str[0] -= 32;
	i = 1;
	while (str[i])
	{
		if (str[i - 1] < 'a' || str[i - 1] > 'z')
		{
			if (str[i - 1] < '0' || str[i - 1] > '9')
			{
				if (str[i - 1] < 'A' || str[i - 1] > 'Z')
				{
					if (str[i] >= 'a' && str[i] <= 'z')
						str[i] -= 32;
				}
			}
			i++;
		}
		else
			i++;
	}
	return (str);
}
