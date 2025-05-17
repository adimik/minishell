/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:46:57 by didimitr          #+#    #+#             */
/*   Updated: 2024/11/04 15:33:35 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s||!fd)
		return;
	while(s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}