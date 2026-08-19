#include <stdio.h>
#include <string.h>

#include "token.h"

/*
 * Initialize token list
 */
void token_list_init(token_list_t *list)
{
    if (list == NULL)
        return;

    list->count = 0;
}

/*
 * Add a token
 */
void token_add(token_list_t *list,
               token_type_t type,
               const char *text)
{
    if (list == NULL || text == NULL)
        return;

    if (list->count >= MAX_TOKENS)
        return;

    token_t *t = &list->tokens[list->count];

    t->type = type;

    strncpy(t->text, text, MAX_TOKEN_LEN - 1);
    t->text[MAX_TOKEN_LEN - 1] = '\0';

    list->count++;
}

/*
 * Convert token type to readable name
 */
static const char *token_name(token_type_t type)
{
    switch (type)
    {
        case TOKEN_WORD:
            return "WORD";

        case TOKEN_PIPE:
            return "PIPE";

        case TOKEN_INPUT:
            return "INPUT";

        case TOKEN_OUTPUT:
            return "OUTPUT";

        case TOKEN_APPEND:
            return "APPEND";

        case TOKEN_BACKGROUND:
            return "BACKGROUND";

        case TOKEN_END:
            return "END";

        default:
            return "UNKNOWN";
    }
}

/*
 * Print token list
 */
void token_print(const token_list_t *list)
{
    if (list == NULL)
        return;

    printf("\n------------- TOKENS -------------\n");

    for (int i = 0; i < list->count; i++)
    {
        printf("%2d : %-12s %-15s\n",
               i,
               token_name(list->tokens[i].type),
               list->tokens[i].text);
    }

    printf("----------------------------------\n");
}
