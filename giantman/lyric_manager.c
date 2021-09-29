/*
** EPITECH PROJECT, 2021
** B-CPE-110-RUN-1-1-antman-thomas.techer
** File description:
** lyric_manager
*/

#include "./include/giantman.h"

lyric_t *create_node(char *str, char i)
{
    lyric_t *node = malloc(sizeof(lyric_t));

    node->word = str;
    node->c = i;
    node ->next = NULL;
    return (node);
}

void push_last_in_list(lyric_t **list, char *str, char i)
{
    lyric_t *node = create_node(str, i);
    lyric_t *tmp = *list;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = node;
}

lyric_t *get_node(lyric_t **list, char c)
{
    lyric_t *tmp = *list;

    while (tmp->next != NULL) {
        if (tmp->c == c)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}