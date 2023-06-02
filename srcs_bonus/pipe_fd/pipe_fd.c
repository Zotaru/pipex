/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:10:05 by root              #+#    #+#             */
/*   Updated: 2023/05/25 03:11:02 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// nb_pipe = nb_cmd - 1

void	security_malloc(int **fd_tab, int i_act)
{
	int	i;

	i = 0;
	while (i < i_act)
	{
		free(fd_tab[i]);
		i++;
	}
	free(fd_tab);
	fd_tab = NULL;
	return ;
}

int	**pipe_fd(int nb_pipe)
{
	int	i;
	int	**fd_tab;

	i = 0;
	fd_tab = malloc(sizeof(int *) * (nb_pipe));
	if (fd_tab == NULL)
		return (NULL);
	while (i < nb_pipe)
	{
		fd_tab[i] = malloc(sizeof(int) * 2);
		if (fd_tab[i] == NULL)
		{
			security_malloc(fd_tab, i);
			return (NULL);
		}
		i++;
	}
	i = 0;
	while (i < nb_pipe)
		pipe(fd_tab[i++]);
	return (fd_tab);
}
