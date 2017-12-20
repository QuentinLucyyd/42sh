/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 08:21:56 by qmanamel          #+#    #+#             */
/*   Updated: 2017/08/22 08:24:15 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit_num(char const *s, char c, int *len)
{
	char	**str;
	size_t	size;
	int		i;
	int		start;

	if (!s)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (ft_splitcounter(s, c) + 1))))
		return (NULL);
	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			str[size++] = ft_strsub(s, start, i - start);
		}
	}
	str[size] = NULL;
	*len = size;
	return (str);
}
