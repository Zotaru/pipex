/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:30:05 by amonier           #+#    #+#             */
/*   Updated: 2023/05/23 18:30:36 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipe(int **fd_tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		close(fd_tab[i][0]);
		close(fd_tab[i][1]);
		i++;
	}
	return ;
}
