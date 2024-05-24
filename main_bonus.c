#include "pipex.h"

// ./pipex infile cmd1 cmd2 cmd3 outfile = 6
// ./pipex heredoc STOP cmd1 cmd2 cmd3 outfile = 7
static int ini_pip(t_pip *pip, int ac, char **av)
{
    if (same_str(av[1], "here_doc"))
    {
        ft_heredoc(av, pip);
        pip->outfile = open(av[ac - 1], W_AP, 0777);
        pip->first_cmd = 3;
    }
    else
    {
        pip->infile = open(av[1], R_ONLY, 0777);
        if (pip->infile < 0)
            return (perror(av[1]), 0);
        pip->outfile = open(av[ac - 1], W_NEW, 0777);
        dup_close(pip->infile, STDIN_FILENO);
        pip->first_cmd = 2;
    }
    if (pip->outfile < 0)
	    return (perror(av[ac - 1]), 0);
	return (1);
}

// ./pipex infile cmd1 cmd2 cmd3 outfile = 6
int	main(int ac, char **av, char **env)
{
    t_pip pip;

    if (ac < 5)
        return (put("not enough args\n"), 1);
    if (!ini_pip(&pip, ac, av))
		return (1);
    pip.i = pip.first_cmd;
    while (++pip.i < ac - 2)
        ft_child(av[pip.i], env, &pip);
    dup_close(pip.outfile, STDOUT_FILENO);
    ft_exec(av[pip.i], env);
	return (0);
}
////////////////////////////////////////////////////////////
