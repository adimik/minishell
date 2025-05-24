/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 02:00:10 by didimitr          #+#    #+#             */
/*   Updated: 2025/05/18 23:04:21 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

#include "minishell.h"

#define TOKENIZER_INIT_SIZE 64
#define NO_TOKEN ((size_t)-1)

typedef struct s_tokens
{
    char    **items;
    size_t  count;
    size_t  mem_size;
} t_tokens;

t_tokens *tokenizer(const char *input);
void    *ft_realloc(void *ptr,size_t old_size);
t_tokens *token_init(size_t init_size);
size_t next_token(const char *input, size_t i, t_tokens *tokens);
size_t skip_white_space(const char *input, size_t i);
size_t  add_new_token(const char *input, size_t i, t_tokens *tokens);
size_t  token_len(const char *input);




#endif
