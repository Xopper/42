#include <stdlib.h>
#include "ray_tracer.h"

t_vertices		*new_vertex(t_vec v)
{
	t_vertices	*new;

	if (!(new =(t_vertices *)malloc(sizeof(t_vertices))))
		return (NULL);
	new->vec = v;
	new->next = NULL;
	return (new);
}

void			push_vertex(t_vertices **begin, t_vertices *new)
{
	t_vertices	*tmp;

	if (!new)
		return ;
	if (!*begin)
		*begin = new;
	else
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_obj			*new_triangle(t_triangle t)
{
	t_obj		*new;

	if (!(new =(t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	new->triangle = t;
	new->next = NULL;
	return (new);
}

void			push_triangle(t_obj **begin, t_obj *new)
{
	t_obj		*tmp;

	if (!new)
		return ;
	if (!*begin)
		*begin = new;
	else
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
