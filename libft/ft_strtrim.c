/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimik <adimik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:15:49 by didimitr          #+#    #+#             */
/*   Updated: 2024/10/30 13:35:28 by adimik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    size_t start;
    size_t end;
    
    if(!s1 || !set)
        return(NULL);
    start = 0;
    end = ft_strlen(s1);
    while (s1[start] && ft_strchr(set, s1[start]))
        start++;      
    while (end > start && ft_strchr(set, s1[end - 1]))
        end--;
    return(ft_substr(s1, start, end - start));
}
