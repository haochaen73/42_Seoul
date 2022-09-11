/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:07:49 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/11 21:07:50 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_sort_string_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_strcmp(f(tab[i]), f(tab[i + 1])) < 0)
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tab[i];
		}
		i++;
	}
}