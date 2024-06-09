/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:06:28 by youmoukh          #+#    #+#             */
/*   Updated: 2024/06/09 21:09:35 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	ft_strlen(char *str)
{
	int	i = 0x0;
	
	if (!str)
		return i;
	while (str[i])
		i++;
	return i;
}

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
	if (num_arg != 0x2)
		return (my_puts("error: cd: bad arguments", 0x2, 0x1), 0x1);
	i = chdir(str);
	if (!i)
		return (my_puts("error: cd: cannot change directory to", 0x2, 0x0), my_puts(str, 0x2, 0x1), 0x1);
	return (0x0);
}

int	execution(char **av, char **env, int num_arg)
{
	int	pipe_fd[2];
	int	is_pipe = ft_strlen(av[num_arg]) && !strcmp(av[num_arg], "|");
	int	check_fork;

	if (!num_arg)
		return (0x0);
	if (!is_pipe && !strcmp(*av, "cd"))
		return (cd(*av, num_arg));
	if (is_pipe && pipe(pipe_fd) == -0x1)
		return (my_puts("error: fatal", 0x2, 0x1), 0x1);
	check_fork = fork();
	if (!check_fork)
	{
		av[num_arg] = 0x0;
		if (is_pipe)
			if (dup2(pipe_fd[0x1], 0x1) == -0x1 || close(pipe_fd[1]) == -0x1 || close (pipe_fd[0]) == -0x1)
				return (my_puts("error: fatal", 0x2, 0x1), 0x1);
		if (!strcmp(*av, "cd"))
			return (cd(*av, num_arg));
		execve(*av, av, env);
        return (my_puts("error: cannot execute ", 0x2, 0x0), my_puts(*av, 0x2, 0x1), 127);
	}
	waitpid(-0x1, 0, 0x0);
	if (is_pipe && (close(pipe_fd[1]) == -0x1 || dup2(pipe_fd[0x0], 0x0) == -0x1 || close (pipe_fd[0]) == -0x1))
		return (my_puts("error: fatal", 0x2, 0x1), 0x1);
	return 0x0;
}

int	main(int ac, char **av, char **env)
{
	int	i = 0x0;
	int	e_s = 0x1;

	if (ac <= 0x1)
		return e_s;
	while (av[i])
	{
		av += ++i;
		i = 0;
		while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			i++;
		e_s = execution(av, env, i);
	}
	return e_s;
}
