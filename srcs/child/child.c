/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:48:13 by root              #+#    #+#             */
/*   Updated: 2023/06/01 19:26:47 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fd_fail(t_pipars *pip, t_vcmd *macmd, int **fd_pipe)
{
	close_pipe(fd_pipe, ft_strlen_double_tab(pip->cmds) - 1);
	clear_double_tab_int(fd_pipe, ft_strlen_double_tab(pip->cmds) - 1);
	if (macmd->path != NULL)
		free(macmd->path);
	clear_double_tab(macmd->cmd);
	clear_pipars(pip);
	exit(0);
}

void	no_path_command(t_pipars *pip, t_vcmd *macmd)
{
	if (macmd->path == NULL)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd((macmd->cmd)[0], 2);
		ft_putstr_fd("\n", 2);
		clear_double_tab(macmd->cmd);
		clear_pipars(pip);
		exit(0);
	}
}

void	fd_infile(t_pipars *pip, t_vcmd *macmd, int **fd_pipe)
{
	int	fd;

	fd = open(pip->infile, O_RDONLY);
	if (fd < 0)
	{
		perror(pip->infile);
		fd_fail(pip, macmd, fd_pipe);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return ;
}

void	fd_outfile(t_pipars *pip, t_vcmd *macmd, int **fd_pipe)
{
	int	fd;

	fd = open(pip->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
	{
		perror(pip->outfile);
		fd_fail(pip, macmd, fd_pipe);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	child(t_pipars *pip, t_vcmd *macmd, int **fd_pipe, int position)
{
	if (position == -1)
		fd_infile(pip, macmd, fd_pipe);
	else
		dup2(fd_pipe[position][0], STDIN_FILENO);
	if (position + 1 == ft_strlen_double_tab(pip->cmds) - 1)
		fd_outfile(pip, macmd, fd_pipe);
	else
		dup2(fd_pipe[position + 1][1], STDOUT_FILENO);
	close_pipe(fd_pipe, ft_strlen_double_tab(pip->cmds) - 1);
	clear_double_tab_int(fd_pipe, ft_strlen_double_tab(pip->cmds) - 1);
	no_path_command(pip, macmd);
	execve(macmd->path, macmd->cmd, pip->envp);
	if (macmd->path != NULL)
		free(macmd->path);
	clear_double_tab(macmd->cmd);
	clear_pipars(pip);
	exit(0);
}
