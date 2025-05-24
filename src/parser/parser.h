/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:51:35 by didimitr          #+#    #+#             */
/*   Updated: 2025/05/24 16:32:51 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "minishell.h"

typedef enum e_token_type 
{
    TOKEN_WORD
}t_token_type;


typedef struct s_token
{
    t_token_type    type;
    char    *value;
    t_token *next;
}   t_token;

#endif