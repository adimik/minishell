/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:44:03 by didimitr          #+#    #+#             */
/*   Updated: 2025/05/18 23:23:02 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv)
{
    t_tokens    *token;
    int i;

    i = 0;
    if(argc < 1)
        return(1);
    token = tokenizer(argv[1]);
    while(token->items[i])
    {
        printf("%s", token->items[i]);
        printf("\n");
        i++;
    }

    return(0);
}