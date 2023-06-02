/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 03:21:32 by amonier           #+#    #+#             */
/*   Updated: 2023/06/01 04:24:40 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	**pipe_and_pid(t_pipars *pip)
{
	int	**fd_pipe;

	fd_pipe = pipe_fd(ft_strlen_double_tab(pip->cmds) - 1);
	if (fd_pipe == NULL)
	{
		if (pip->status_here_doc == 1)
			unlink("here_doc");
		return (free(pip->infile), free(pip->outfile),
			clear_double_tab(pip->cmds), NULL);
	}
	pip->pid = malloc(sizeof(int) * pip->nbcmd);
	if (pip->pid == NULL)
	{
		if (pip->status_here_doc == 1)
			unlink("here_doc");
		return (free(pip->infile), free(pip->outfile),
			clear_double_tab(pip->cmds),
			clear_double_tab_int(&(pip->pid), pip->nbcmd), NULL);
	}
	return (fd_pipe);
}

int	main(int argc, char **argv, char **envp)
{
	int			**fd_pipe;
	t_pipars	pip;

	fd_pipe = NULL;
	parsing(&pip, argc, argv);
	if (pip.infile == NULL || pip.outfile == NULL || pip.cmds == NULL)
		return (0);
	pip.envp = envp;
	pip.paths = environment(envp);
	pip.nbcmd = argc - 3;
	if (pip.status_here_doc == 1)
		pip.nbcmd = argc - 4;
	fd_pipe = pipe_and_pid(&pip);
	if (fd_pipe == NULL)
		return (0);
	pipex(&pip, fd_pipe);
	if (pip.status_here_doc == 1)
		unlink("here_doc");
	clear_double_tab_int(fd_pipe, ft_strlen_double_tab(pip.cmds) - 1);
	free(pip.pid);
	clear_pipars(&pip);
	return (1);
}
