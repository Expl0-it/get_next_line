/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:01:06 by mamichal          #+#    #+#             */
/*   Updated: 2024/03/25 13:35:13 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// input output system calls
# include <unistd.h>
// file options
# include <fcntl.h>

// compile time modifiable size for buffer
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

// linked list to hold file content
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

/*
 * @brief Return a single line form a file fd
 *
 * @param fd file desriptor of a file to read from
 * @return Content of a single line from fd (including the \n character) or
 * NULL on error or if there is nothing left to be read
 */
char	*get_next_line(int fd);

#endif
