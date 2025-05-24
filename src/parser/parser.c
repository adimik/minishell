/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:51:24 by didimitr          #+#    #+#             */
/*   Updated: 2025/05/24 21:49:16 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h" 

t_token	*tokens_to_ll(void)
{
	t_tokens	*arr;
	t_token		*head;
	t_token		*tail;
	size_t		i;

	i = 0;
	arr = tokenizer("Ahoj jak se mas");
	if (!arr)
		return(NULL);
	while(i < arr->count - 1)
	{
		add_obj(tail, arr, i);

	}
}
void	add_obj(t_token **tail, char **arr, int i)
{
	t_token *new_tail;
	
	new_tail = malloc(sizeof(t_token));
	if(!new_tail)
		return(NULL);
	(*tail)->next = new_tail;
	new_tail->next = NULL;
	new_tail->value = arr[i];
	return;
}