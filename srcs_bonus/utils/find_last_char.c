/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 02:52:41 by amonier           #+#    #+#             */
/*   Updated: 2023/05/25 03:11:34 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	find_last_char(char *str, char c)
{
	int	i;
	int	final_pos;

	i = 0;
	final_pos = -1;
	while (str[i])
	{
		if (str[i] == c)
			final_pos = i;
		i++;
	}
	return (final_pos);
}
