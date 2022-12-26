/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:35:11 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/03 17:16:47 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <stdio.h>
# include <stdlib.h>
# include "ft_printf.h"

typedef struct s_vars
{
	char	*infile;
	char	*outfile;
	int		fd_in;
	int		fd_out;
	char	**cmd_path;
	char	**path;
	char	***argv;
	char	**envp;
	size_t	cmd_num;
}	t_vars;

void	parse(t_vars *vars, int argc, char **argv, char **envp);
void	ft_error(int n, char *str);
int		arg_check(int argc, char **argv);
void	pipex(t_vars *vars);
void	parse_path(t_vars *vars, char **envp);
void	search_path(t_vars *vars);

void	free_split(char **ptr);
char	**ft_split(char const *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
