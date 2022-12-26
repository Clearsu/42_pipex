/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:08:36 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/21 19:33:37 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	dup2_and_close(t_vars *vars, int prev_read_end,
		int fd_pipe[], size_t i)
{
	if (i == 0)
	{
		vars->fd_in = open(vars->infile, O_RDONLY);
		dup2(vars->fd_in, 0);
		close(vars->fd_in);
	}
	else
	{
		dup2(prev_read_end, 0);
		close(prev_read_end);
	}
	close(fd_pipe[0]);
	if (i == vars->cmd_num - 1)
	{
		vars->fd_out = open(vars->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0666);
		dup2(vars->fd_out, 1);
		close(vars->fd_out);
	}
	else
	{
		dup2(fd_pipe[1], 1);
		close(fd_pipe[1]);
	}
}

static void	multiple_pipes(t_vars *vars, size_t i)
{
	pid_t		pid;
	int			fd_pipe[2];
	static int	prev_read_end;

	if (i < vars->cmd_num - 1)
		pipe(fd_pipe);
	pid = fork();
	if (pid > 0)
	{
		if (i > 0)
			close(prev_read_end);
		prev_read_end = fd_pipe[0];
		close(fd_pipe[1]);
		return ;
	}
	dup2_and_close(vars, prev_read_end, fd_pipe, i);
	execve(vars->cmd_path[i], vars->argv[i], vars->envp);
}

void	pipex(t_vars *vars)
{
	size_t	i;

	i = 0;
	while (i < vars->cmd_num)
		multiple_pipes(vars, i++);
	i = 0;
	while (i++ < vars->cmd_num)
		wait(NULL);
}
