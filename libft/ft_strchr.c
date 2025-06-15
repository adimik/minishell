/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:17:46 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 15:17:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *str, int c)
{
	const char	*p;

	p = str;
	while (1)
	{
		if (*p == (char)c)
			return ((char *)p);
		if (*p == '\0')
			break ;
		p++;
	}
	return (NULL);
}
