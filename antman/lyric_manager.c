/*
** EPITECH PROJECT, 2021
** B-CPE-110-RUN-1-1-antman-thomas.techer
** File description:
** lyric_manager
*/

#include "./include/antman.h"

lyric_t *create_node(char *str)
{
    lyric_t *node = malloc(sizeof(lyric_t));

    node->word = str;
    node->i = 1;
    node ->next = NULL;
    return (node);
}

void push_last_in_list(lyric_t **list, char *str)
{
    lyric_t *node = create_node(str);
    lyric_t *tmp = *list;
    int ind = 0;

    node->indx = ind;
    while (tmp->next != NULL) {
        ind = tmp->indx;
        tmp = tmp->next;
    }
    node->indx = ind + 1;
    tmp->next = node;
}

lyric_t *get_node(lyric_t **list, char *str)
{
    lyric_t *tmp = *list;

    while (tmp->next != NULL) {
        if (!my_strcmp(tmp->word, str))
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}