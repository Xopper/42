/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 20:09:04 by jbalestr          #+#    #+#             */
/*   Updated: 2016/04/04 16:13:53 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "gnl.h"

static int	read_comment(char *line)
{
	if (line[0] == '#')
	{
		if (!ft_strcmp(line, "##start"))
			return (return_free(line, 0, "Command before ant number"));
		if (!ft_strcmp(line, "##end"))
			return (return_free(line, 0, "Command before ant number"));
		return (1);
	}
	return (-1);
}

static int	read_ant_count(char *line)
{
	char	**tmp;
	int		count;

	tmp = ft_splitwhite(line);
	if (ft_strlen_tab(tmp) == 1 && is_number(tmp[0]))
	{
		count = ft_atoi(line);
		free_split(tmp);
		if (!count)
			return (return_free(line, 0, "Ant number must be > 0"));
		return (return_free(line, ft_atoi(line), ""));
	}
	else
	{
		free_split(tmp);
		return (return_free(line, 0, "Expecting ant number"));
	}
	return (-1);
}

int			read_num_ant(int fd)
{
	char	*line;
	int		ret;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (line)
		{
			ft_putendl(line);
			if (!ft_strlen(line))
				return (return_free(line, 0, "Empty line"));
			ret = read_comment(line);
			if (!ret)
				return (0);
			else if (ret == -1)
			{
				if ((ret = read_ant_count(line)) != -1)
					return (ret);
			}
			free(line);
		}
		else
			return (return_print(0, "Empty line"));
	}
	return (return_print(0, "Didn't found ant numer"));
}
