/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:06:28 by youmoukh          #+#    #+#             */
/*   Updated: 2024/06/07 18:40:05 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	my_puts(char *str, int fd, int f_newline)
{
	int	i = 0x0;

	while (str[i])
		write(fd, &str[i++], 0x1);
	if (f_newline == 0x1)
		write(fd, "\n", 0x1);
}

int	cd(char *str, int num_arg)
{
	int	i = 0x0;

	if (num_arg > 0x1)
		return (my_puts("", 0x2, 0x1), 0x1);
	i = chdir(str);
	if (!i)
		return (my_puts("", 0x2, 0x1), 0x1);
}

int	execution(char *av, char **env)
{

}

int	main(int ac, char **av, char **env)
{
	int	i = 0x0;
	int	e_s = 0x0;

	if (ac > 1)
	{
		while (av[i])
		{
			while (av[i] && strcmp(av[i], ";") &&  strcmp(av[i], "|"))
				i++;
			e_s = execution();
		}
	}
	if (ac == 0x1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
