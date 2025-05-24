/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 23:09:13 by didimitr          #+#    #+#             */
/*   Updated: 2025/05/18 23:05:19 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


t_tokens *tokenizer(const char *input)
{
    t_tokens *tokens;
    size_t  i;
    
    tokens = token_init(TOKENIZER_INIT_SIZE);
    i = 0;
    while(input[i])
    {
        if(tokens->count + 1 >= tokens->mem_size)
        {
            tokens->items = ft_realloc(tokens->items, tokens->mem_size * sizeof *tokens->items);
            tokens->mem_size *= 2;
        }
        i = next_token(input, i, tokens);
        if(i == NO_TOKEN)
            break;
    }
    tokens->items[tokens->count] = NULL;
    return(tokens);
}

void    *ft_realloc(void *ptr,size_t old_size)
{
    void    *new_ptr;

    if (old_size > SIZE_MAX / 2)
    return NULL;
    new_ptr = malloc(old_size * 2);
    if(!new_ptr)
        return(NULL);
    ft_bzero(new_ptr, old_size * 2);
    ft_memcpy(new_ptr, ptr, old_size);
    free(ptr);
    return(new_ptr);
}

t_tokens *token_init(size_t init_size)
{
    t_tokens *tokens;
    tokens = malloc(sizeof(t_tokens));
    if(!tokens)
    return(NULL);
    tokens->items = malloc(init_size * sizeof tokens->items);
    tokens->count = 0;
    tokens->mem_size = init_size;
    return(tokens);
}

size_t next_token(const char *input, size_t i, t_tokens *tokens)
{
    i = skip_white_space(input, i);
    if(!input[i])
        return(NO_TOKEN);
    i = add_new_token(input, i, tokens);
    if(!input[i])
        return(NO_TOKEN);
    return(i);
}

size_t skip_white_space(const char *input, size_t i)
{
    while(input[i] && (input[i] == 32 || input[i] == '\t'))
    {
        i++;
    }
    return(i);
}

size_t  add_new_token(const char *input, size_t i, t_tokens *tokens)
{
    size_t  len;
    char    *token;
    
    len = token_len(input + i);
    token = malloc(len * sizeof(char) + 1);
    if(!token)
        return(NO_TOKEN);
    ft_memcpy(token, &input[i], len);
    token[len] = '\0';
    tokens->items[tokens->count] = token;
    tokens->count++;
    return(i + len);
}

size_t  token_len(const char *input)
{
    size_t  i;

    i = 0;
    while(input[i] && (input[i] != ' ' && input[i] != '\t'))
    {
        i++;
    }
    return(i);
}