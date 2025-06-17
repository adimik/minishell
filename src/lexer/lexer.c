/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 23:09:13 by didimitr          #+#    #+#             */
/*   Updated: 2025/06/17 18:29:30 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*tokenizer(const char *input)
{
	t_token	*head;
	int		i;

	head = NULL;
	i = 0;
	if (read_full_input(input) != 0)
		return (NULL);
	while (input[i])
	{
		while (input[i] == ' ')
			i++;
		if (input[i])
			i += new_token(&head, input, i);
	}
	return (head);
}

int	new_token(t_token **head, const char *input, int i)
{
	int		len;
	char	*value;
	t_token	*new;

	len = token_len(input, i);
	if (len == 0 && is_operator(input))
		len = 1;
	if (len == 0)
		return (0);
	if (input[i] == '\'' || input[i] == '\"')
		value = ft_substr(input, i, len);
	else
		value = ft_substr(input, i, len);
	if (!value)
		return (0);
	new = new_node(value);
	if (!new)
	{
		free(value);
		return (0);
	}
	add_token_to_list(head, new);
	return (len);
}

t_token	*new_node(char *value)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->value = value;
	new->type = get_token_type(value);
	new->next = NULL;
	return (new);
}

int	token_len(const char *input, int i)
{
	int				len;
	t_quote_state	q;
	char			c;

	len = 0;
	q.s_quotes = 0;
	q.d_quotes = 0;
	if (is_operator(&input[i]) > 0)
		return (is_operator(&input[i]));
	while (input[i + len])
	{
		c = input[i + len];
		if (is_escaped(input, i + len, &q))
		{
			len += 2;
			continue ;
		}
		if (!q.s_quotes && !q.d_quotes && (c == ' ' || is_operator(&input[i
						+ len]) > 0))
			break ;
		update_quote_state(c, &q);
		len++;
	}
	return (len);
}

int	read_full_input(const char *input)
{
	t_quote_state	q;
	int				i;

	q.s_quotes = 0;
	q.d_quotes = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' && q.d_quotes == 0 && is_escaped(input, i, &q))
			q.s_quotes ^= 1;
		else if (input[i] == '"' && q.s_quotes == 0 && is_escaped(input, i, &q))
			q.d_quotes ^= 1;
		i++;
	}
	if (q.s_quotes || q.d_quotes)
		return (unclosed_input());
	return (0);
}
