/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 02:00:10 by didimitr          #+#    #+#             */
/*   Updated: 2025/06/17 18:22:28 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

typedef enum s_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC,
	TOKEN_ENV_VAR,
	TOKEN_EOF
}					t_token_type;

typedef struct s_quotes_state
{
	int				s_quotes;
	int				d_quotes;
}					t_quote_state;

typedef struct s_token
{
	char			*value;
	struct s_token	*next;
	t_token_type	type;
}					t_token;

t_token				*tokenizer(const char *input);
int					new_token(t_token **head, const char *input, int i);
int					token_len(const char *input, int i);
void				add_token_to_list(t_token **head, t_token *new);
t_token_type		get_token_type(char *value);
void				free_ll(t_token *list);
int					read_full_input(const char *input);
int					unclosed_input(void);
t_token				*new_node(char *value);
int					is_operator(const char *s);
int					is_escaped(const char *input, int index, t_quote_state *q);
void				update_quote_state(char c, t_quote_state *q);

#endif
