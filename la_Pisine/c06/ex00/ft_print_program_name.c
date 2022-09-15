/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjki <youngjki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:59:59 by youngjki          #+#    #+#             */
/*   Updated: 2022/09/04 06:26:57 by youngjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchars(char *name)
{
	while (*name)
	{
		write(1, name, 1);
		name++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		putchars(argv[0]);
}
