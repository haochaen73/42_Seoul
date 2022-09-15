/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:17:47 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/10 18:03:27 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char	*src)
{
	int	cnt;

	cnt = 0;
	while (*src)
	{
		cnt++;
		src++;
	}
	return (cnt);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dup)
		return (dup);
	while (*src)
	{
		dup[i] = *src++;
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*name;

	name = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		name[i].size = ft_strlen(av[i]);
		name[i].str = av[i];
		name[i].copy = ft_strdup(av[i]);
		i++;
	}
	name[i].str = 0;
	return (name);
}
