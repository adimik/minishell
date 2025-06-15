/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 02:00:10 by didimitr          #+#    #+#             */
/*   Updated: 2025/06/15 11:46:20 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

#include "minishell.h"

typedef enum s_token_type
{
    TOKEN_WORD,          // Regular word
    TOKEN_PIPE,          // Pipe symbol '|'
    TOKEN_REDIRECT_IN,   // Input redirection '<'
    TOKEN_REDIRECT_OUT,  // Output redirection '>'
    TOKEN_APPEND,        // Append output '>>'
    TOKEN_HEREDOC,       // Heredoc '<<'
    TOKEN_ENV_VAR,       // Environment variable (e.g., $VAR)
    TOKEN_WHITESPACE,    // Whitespace
    TOKEN_EOF            // End of file/input
}t_token_type;


typedef struct s_token
{
    char    *value;
    struct s_token  *next;
    t_token_type    type;
} t_token;

t_token *tokenizer(const char *input);
int new_token(t_token **head, const char *input, int i);
int token_len(const char *input, int i);
void    add_token_to_list(t_token **head, t_token *new);
t_token_type    get_token_type(char *value);
void    free_ll(t_token *list);
int read_full_input(const char *input);



#endif
