/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 01:42:05 by amonier           #+#    #+#             */
/*   Updated: 2023/05/25 03:11:55 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	close_pipe_wait(t_pipars *pip, int **fd_pipe)
{
	int	i;

	i = 0;
	close_pipe(fd_pipe, ft_strlen_double_tab(pip->cmds) - 1);
	while (i < pip->nbcmd)
	{
		waitpid((pip->pid)[i], NULL, 0);
		i++;
	}
	return ;
}

void	pipex(t_pipars *pip, int **fd_pipe)
{
	int		i;
	t_vcmd	macmd;

	i = 0;
	while (i < pip->nbcmd)
	{
		create_cmd(pip, &macmd, i);
		(pip->pid)[i] = fork();
		if ((pip->pid)[i] == 0)
		{
			free(pip->pid);
			child(pip, &macmd, fd_pipe, i - 1);
		}
		else
		{
			if (macmd.path != NULL)
				free(macmd.path);
			clear_double_tab(macmd.cmd);
		}
		i++;
	}
	close_pipe_wait(pip, fd_pipe);
	return ;
}
