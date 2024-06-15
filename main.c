/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:12:00 by kalipso           #+#    #+#             */
/*   Updated: 2024/06/15 17:12:00 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

///////////////////////////////////////////////////////////////////////////////]
// FD_CLOEXEC = close the file descriptor upon executing a new program
static void	ini_pip(t_pip *pip, int ac, char **av)
{
	ft_memset(pip, 0, sizeof(t_pip));
	pip->infile = open(av[1], O_RDONLY | FD_CLOEXEC, 0777);
	pip->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC | \
						FD_CLOEXEC, 0777);
	if (pip->infile < 0 || pip->outfile < 0)
	{
		perror("open");
		exit(1);
	}
	pip->first_cmd = 2;
	dup_close(pip->infile, STDIN_FILENO);
}

///////////////////////////////////////////////////////////////////////////////]
// ./pipex infile cmd1 cmd2 cmd3 outfile = 6
int	main(int ac, char **av, char **env)
{
	t_pip	pip;

	if (ac < 5)
		return (put("not enough args\n"), 1);
	ini_pip(&pip, ac, av);
	pip.i = 1;
	while (++pip.i < ac - 2)
		ft_child(av[pip.i], env, &pip);
	dup_close(pip.outfile, STDOUT_FILENO);
	ft_exec(av[pip.i], env);
	return (0);
}
