/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:00:55 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/24 18:19:05 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	alloc_list(&list, fd);
	if (NULL == list)
		return (NULL);
	next_line = get_line(list);
	clear_list_till_nl(&list);
	return (next_line);
}

void	alloc_list(t_list **list, int fd)
{
	int		bytes_read;
	char	*buf;

	while (!found_nl(*list))
	{
		buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (NULL == buf)
			return ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(buf);
			return ;
		}
		buf[bytes_read] = 0;
		list_append(list, buf);
	}
}

void	list_append(t_list **list, char *buf)
{
	t_list	*last_node;
	t_list	*new_node;

	last_node = ft_lstlast(*list);
	new_node = (t_list *)malloc(sizeof(t_list));
	if (NULL == new_node)
		return ;
	if (NULL == last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->content = (char *)buf;
	new_node->next = NULL;
}
	char	*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	return (line);
}
