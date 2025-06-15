/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 17:44:03 by didimitr          #+#    #+#             */
/*   Updated: 2025/06/14 16:19:32 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
    int g_exit_status = 0;
    t_token *list;
    char *prompt;
    t_token *tmp;
    while(1)
    {
        prompt = readline("minishell$ ");
        list = tokenizer(prompt);
        tmp = list;
        while(tmp)
        {
            printf("token:%s\n", tmp->value);
            tmp = tmp->next;
        }
        free_ll(list);
        free(prompt);
    }

    return(0);
}