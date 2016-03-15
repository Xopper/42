/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:14:30 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/15 14:18:40 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			main(int argc, char **argv)
{
	t_graph	*graph;

	if (argc == 2)
	{
		if (!(graph = read_map(argv[1])))
			return (0);
		dijkstra(graph);
		destroy_graph(graph);
	}
	else
		printf("Usage: ./lemin map\n");
	return 0;
}
