/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 02:54:14 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/03 17:22:17 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	single_pipe(t_vars *vars)
{
	pid_t	pid;
	int		fd_pipe[2];

	pipe(fd_pipe);
	pid = fork();
	if (pid > 0)
	{
		close(fd_pipe[1]);
		dup2(fd_pipe[0], 0);
		close(fd_pipe[0]);
		dup2(vars->fd_out, 1);
		wait(NULL);
		execve(vars->cmd_path[1], vars->argv[1], vars->envp);
	}
	else
	{
		close(fd_pipe[0]);
		dup2(vars->fd_in, 0);
		dup2(fd_pipe[1], 1);
		close(fd_pipe[1]);
		execve(vars->cmd_path[0], vars->argv[0], vars->envp);
	}
}

void	pipex(t_vars *vars)
{
	vars->fd_in = open(vars->infile, O_RDONLY);
	vars->fd_out = open(vars->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0666);
	single_pipe(vars);
	close(vars->fd_in);
	close(vars->fd_out);
}
