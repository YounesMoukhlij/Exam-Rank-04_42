/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:06:28 by youmoukh          #+#    #+#             */
/*   Updated: 2024/06/07 18:25:15 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int	main(int ac, char **av, char **env)
{
	int	i = 0x0;
	int	e_s;

	if (ac > 1)
	{
		while (av[i])
		{
			e_s = execution();	
		}
	}
	if (ac == 0x1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
