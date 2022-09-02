/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim2 <hyunskim@student.42seoul.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:41:22 by hyunkim2          #+#    #+#             */
/*   Updated: 2022/08/28 07:55:06 by hyunkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);

int	is_possible(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}	
	if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		return (0);
	return (res);
}

int	main(int ac, char **av)
{
	int	res1;
	int	res2;

	if (ac != 3)
		return (0);
	res1 = is_possible(av[1]);
	res2 = is_possible(av[2]);
	rush(res1, res2);
	return (0);
}
