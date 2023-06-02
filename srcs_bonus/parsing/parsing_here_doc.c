/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_here_doc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:35:12 by amonier           #+#    #+#             */
/*   Updated: 2023/06/01 00:01:05 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	create_here_doc(char **argv)
{
	int		fd;
	char	*temp;
	int		len_limiter;

	len_limiter = ft_strlen(argv[2]);
	fd = open("here_doc", O_RDWR | O_CREAT, 0777);
	if (fd < 0)
		error_exit();
	while (1)
	{
		temp = get_next_line(0);
		if (!temp)
			break ;
		if (ft_strncmp(temp, argv[2], len_limiter) == 0
			&& temp[len_limiter] == '\n')
			break ;
		if (ft_strncmp(temp, argv[2], len_limiter) == 0
			&& temp[len_limiter] == '\0')
			break ;
		ft_putstr_fd(temp, fd);
		free(temp);
	}
	free(temp);
	close(fd);
	return ;
}

int	parsing_here_doc_normi(t_pipars *pip, int argc, char **argv)
{
	pip->infile = ft_strdup(argv[1]);
	if (pip->infile == NULL)
	{
		unlink("here_doc");
		return (0);
	}
	pip->outfile = ft_strdup(argv[argc - 1]);
	if (pip->outfile == NULL)
	{
		unlink("here_doc");
		return (free(pip->infile), 0);
	}
	pip->cmds = malloc(sizeof(char *) * (argc - 4 + 1));
	if (pip->cmds == NULL)
	{
		unlink("here_doc");
		return (free(pip->infile), free(pip->outfile), 0);
	}
	return (1);
}

void	parsing_here_doc(t_pipars *pip, int argc, char **argv)
{
	int	i;
	int	j;

	pip->status_here_doc = 1;
	if (argc < 6)
		error_exit();
	create_here_doc(argv);
	if (parsing_here_doc_normi(pip, argc, argv) == 0)
		return ;
	i = 0;
	j = 3;
	while (i < argc - 4)
	{
		(pip->cmds)[i] = ft_strdup(argv[j]);
		if ((pip->cmds)[i] == NULL)
		{
			unlink("here_doc");
			return (free_all_security(pip, i));
		}
		i++;
		j++;
	}
	(pip->cmds)[i] = NULL;
	return ;
}
