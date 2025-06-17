/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:02:46 by didimitr          #+#    #+#             */
/*   Updated: 2025/06/17 18:07:03 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unclosed_input(void)
{
	g_exit_status = 258;
	printf("syntax error: unexpected EOF while looking for matching quote\n");
	return (g_exit_status);
}

int	is_escaped(const char *input, int index, t_quote_state *q)
{
	char	next;

	if (q->s_quotes)
		return (0);
	if (input[index] != '\\')
		return (0);
	next = input[index + 1];
	if (!next)
		return (0);
	if (!q->d_quotes)
		return (1);
	return (next == '"' || next == '\\' || next == '$' || next == '`');
}

void	update_quote_state(char c, t_quote_state *q)
{
	if (c == '\'' && !q->d_quotes)
		q->s_quotes ^= 1;
	else if (c == '"' && !q->s_quotes)
		q->d_quotes ^= 1;
}

int	is_operator(const char *s)
{
	if (!s)
		return (0);
	if ((s[0] == '>' || s[0] == '<') && s[1] == s[0])
		return (2);
	if (s[0] == '>' || s[0] == '<' || s[0] == '|')
		return (1);
	return (0);
}

t_token_type	get_token_type(char *value)
{
	if (!value || *value == '\0')
		return (TOKEN_EOF);
	if (ft_strncmp(value, ">>", 2) == 0)
		return (TOKEN_APPEND);
	if (ft_strncmp(value, "<<", 2) == 0)
		return (TOKEN_HEREDOC);
	if (ft_strncmp(value, ">", 1) == 0)
		return (TOKEN_REDIRECT_OUT);
	if (ft_strncmp(value, "<", 1) == 0)
		return (TOKEN_REDIRECT_IN);
	if (ft_strncmp(value, "|", 1) == 0)
		return (TOKEN_PIPE);
	if (value[0] == '$')
		return (TOKEN_ENV_VAR);
	return (TOKEN_WORD);
}
