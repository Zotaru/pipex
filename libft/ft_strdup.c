/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <amonier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:25:32 by amonier           #+#    #+#             */
/*   Updated: 2023/05/20 23:05:14 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strdup(char *src)
{
	char	*str;
	int		l;
	int		i;

	if (src == NULL)
		return (NULL);
	l = ft_strlen(src);
	str = malloc((l + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	*str;
	char	str2[5] = "abcde";
	str = ft_strdup(str2);
	printf("%s = %s",str2, str);
	free(str);
}*/
