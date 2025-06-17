/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:55:53 by didimitr          #+#    #+#             */
/*   Updated: 2025/06/17 17:55:53 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_l;
	size_t	src_l;

	if (size == 0)
		return (ft_strlen(src));
	dest_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	if (size <= dest_l)
		return (size + src_l);
	i = 0;
	while (src[i] && i < size - dest_l - 1)
	{
		dst[dest_l + i] = src[i];
		i++;
	}
	dst[dest_l + i] = '\0';
	return (dest_l + src_l);
}
