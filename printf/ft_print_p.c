/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimik <adimik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:39:33 by didimitr          #+#    #+#             */
/*   Updated: 2024/11/21 12:48:59 by adimik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(void *p)
{
	unsigned long int	i;

	i = (unsigned long int)p;
	if (!p)
		return (ft_print_s("(nil)"));
	ft_print_s("0x");
	return (ft_print_x(i) + 2);
}
