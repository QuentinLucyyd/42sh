/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmanamel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 13:00:24 by qmanamel          #+#    #+#             */
/*   Updated: 2017/07/30 14:12:05 by qmanamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/42sh.h"

int 		ft_parse_check(char *str)
{
	int 	i;
	char 	**split;

	split = ft_strsplit(str, ';');
	if (!split)
		return(1);
	i = -1;
	while (str[++i])
	{
		if (str[i] == ';' && str[i + 1] == ';')
		{
			ft_putendl("42sh: parse error near ';;'");
			return(1);
		}
	}
	return (0);
}

char			**local_init(void)
{
	char **tmp;

	tmp = (char **)malloc(sizeof(char *) * 2);
	tmp[0] = ft_strdup("initialized");
	tmp[1] = NULL;
	return (tmp);
}

int			main()
{
	char	*input;
	int		ret;
	char	**commands;
	struct termios	tattr;
	
	tcgetattr(STDIN_FILENO, &tattr);
	ft_putstr(CLEAR);
	g_local = local_init();
	new_env();
	while (42)
	{
		display_prompt();
		input = ft_read();
		tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
		input = ft_strtrim(input);
		if (ft_isemptystr(input) || ft_parse_check(input) || !ft_strcmp(input, ";"))
		{
			free(input);
			continue ;
		}
		commands = ft_strsplit(input, ';');
		free(input);
		ret = run_cmds(commands);
		ft_freestrarr(commands);
		if (!ret)
			exit_shell();
	}
	ft_freestrarr(g_shell->g_env);
	return (0);
}
