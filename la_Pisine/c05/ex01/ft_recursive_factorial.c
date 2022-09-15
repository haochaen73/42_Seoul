/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:28:53 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/03 17:00:43 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	n;

	n = nb;
	if (n < 0)
		return (0);
	if (n == 0)
		return (1);
	return (n * ft_recursive_factorial(n - 1));
}
