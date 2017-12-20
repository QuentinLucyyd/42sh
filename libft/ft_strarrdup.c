/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 08:01:29 by qmanamel          #+#    #+#             */
/*   Updated: 2017/09/21 08:01:44 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarrdup(char **str)
{
	int 	i;
	char 	**f_str;

	i = -1;
	while (str[++i])
		i++;
	f_str = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (str[++i])
		f_str[i] = ft_strdup(str[i]);
	return(f_str);
}
