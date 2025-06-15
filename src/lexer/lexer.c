/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 23:09:13 by didimitr          #+#    #+#             */
/*   Updated: 2025/06/15 11:46:57 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token *tokenizer(const char *input)
{
    t_token *head;
    int     i;

    head = NULL;
    i = 0;
    if (read_full_input(input) != 0)
        return(NULL);
    while(input[i])
    {
        while(input[i] == ' ')
            i++;
        if(input[i])
            i += new_token(&head, input, i);
    }
    return(head);
}
int new_token(t_token **head, const char *input, int i)
{
    int len;
    char    *value;
    t_token *new;

    len = token_len(input, i);
    if (len == 0)
        return(0);
    if (len == -1)
        new_readline();
    value = ft_substr(input, i, len);
    if (!value)
        return(0);
    new = malloc(sizeof(t_token));
    if (!new)
    {
        free(value);
        return 0;
    }
    new->value = value;
    new->type = get_token_type(value);
    new->next = NULL;
    add_token_to_list(head, new);
    return len;
}

int token_len(const char *input, int i)
{
    int len;
    int quote;

    quote = 0;
    len = 0;
    while((input[len + i] && input[len + i] != ' ') || (quote == 1 && input[len + i]))
    {
        if(input[i] == '\'')
            quote = 1;
        len++;
    }
    if(quote == 1)
        return(-1);
    return(len);
}

void    add_token_to_list(t_token **head, t_token *new)
{
    t_token *tmp;
    
    tmp = *head;
    if(!*head)
        *head = new;
    else
    {
        while(tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}
t_token_type get_token_type(char *value)
{
    if (!value || *value == '\0')
        return TOKEN_EOF;
    if (ft_strncmp(value, ">>", 2) == 0)
        return TOKEN_APPEND;
    if (ft_strncmp(value, "<<", 2) == 0)
        return TOKEN_HEREDOC;
    if (ft_strncmp(value, ">", 1) == 0)
        return TOKEN_REDIRECT_OUT;
    if (ft_strncmp(value, "<", 1) == 0)
        return TOKEN_REDIRECT_IN;
    if (ft_strncmp(value, "|", 1) == 0)
        return TOKEN_PIPE;
    if (value[0] == '$')
        return TOKEN_ENV_VAR;
    return TOKEN_WORD;
}
void    free_ll(t_token *list)
{
    t_token *tmp;

    while(list)
    {
        tmp = list->next;
        free(list->value);
        free(list);
        list = tmp;
    }
}

int read_full_input(const char *input)
{
    int single_q;
    int double_q;
    int i;

    single_q = 0;
    double_q = 0;
    i = 0;
    while(input[i])
    {
        if(input[i] == '\'')
        {
            if(double_q == 0 && single_q == 0)
                single_q = 1;
            else if(single_q == 1)
                single_q = 0;
        }
        if(input[i] == '\"')
        {
            if(single_q == 0 && double_q == 0)
                double_q = 1;
            else if(double_q == 1)
                double_q = 0;
        }
        i++;
    }
    if(single_q == 1 || double_q == 1)
        return(unclosed_input(input));
    return(0);
}
int unclosed_input(char *input)
{
    int g_exit_status = 0;

    write(2, "syntax error: unexpected EOF while looking for matching quote\n", 60);
    return(g_exit_status);
}
