/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 04:13:36 by amonier           #+#    #+#             */
/*   Updated: 2023/05/25 03:10:41 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**environment(char **envp)
{
	int		i;

	i = 0;
	while (envp && envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (ft_split(envp[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

// char	**environment(char **envp)
// {
// 	int		i;
// 	char	**final_path;

// 	i = 0;
// 	while (ft_strncmp(envp[i], "PATH=", 5))
// 		i++;
// 	envp[i] += 5;
// 	final_path = ft_split(envp[i], ':');
// 	return (final_path);
// }