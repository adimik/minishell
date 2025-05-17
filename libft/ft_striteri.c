/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:19:17 by didimitr          #+#    #+#             */
/*   Updated: 2024/11/04 14:30:39 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void ft_striteri(char *s, void (*f)(unsigned int,
char*))
{
	unsigned	i;
	
	if(!s || !f)
		return;
	
	i = 0;
	while(s[i])
	{
		f(i, &s[i]);
		i++;
	}
}