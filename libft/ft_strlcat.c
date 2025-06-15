/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:23:10 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 13:23:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t ft_strlcat(char * dst,const char * src, size_t size)
{
    size_t i;
    size_t dest_l;
    size_t src_l; 
    
    if (size == 0)
        return ft_strlen(src);

    dest_l = ft_strlen(dst);
    src_l = ft_strlen(src);

    if (size <= dest_l)
        return (size + src_l);
   
    i = 0;
    while (src[i] && i < size - dest_l -1)
    {
        dst[dest_l + i] = src[i];
        i++;
    }
    dst[dest_l + i] = '\0';
    return (dest_l + src_l);
}
