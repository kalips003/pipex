/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:16:57 by agallon           #+#    #+#             */
/*   Updated: 2024/04/09 23:07:19 by agallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

#define R_ONLY (O_RDONLY | O_CLOEXEC)
#define W_AP (O_WRONLY | O_CREAT | O_APPEND | O_CLOEXEC)
#define W_NEW (O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC)
#define STDIN 0
#define STDOUT 1
#define STDERR 1

// # define O_CLOEXEC 0x80000

typedef struct s_pip {
    int	infile;
    int	outfile;
    int i;
    int first_cmd;
}   t_pip;

/*              A OUTILS               */
// static int		same_str_n(char *gnl0, char *stop_w)
void	ft_heredoc(char **av, t_pip *pip);
void    ft_child(char *raw_cmd, char **env, t_pip *pip);
void    dup_close(int fd_replace, int fd_erase);

/*              FT_EXEC                */
// char	**parse_path(char **env);
// char *find_cmd(char *command, char **env);
// char	*find_parsing(char *command, char **env);
void    ft_exec(char *raw_cmd, char **env);


#endif
