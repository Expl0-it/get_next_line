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
	char	*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	return (line);
}
