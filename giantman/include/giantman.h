/*
** EPITECH PROJECT, 2021
** GIANTMAN
** File description:
** giantman
*/

#ifndef GIANTMAN_H_
#define GIANTMAN_H_

#include "./my.h"
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct lyric_h
{
    char *word;
    char c;
    struct lyric_h *next;
} lyric_t;


int step_one_lyric(char *str);
int decompress_1(char *str);
lyric_t *create_node(char *str, char c);
lyric_t *get_node(lyric_t **list, char c);
void push_last_in_list(lyric_t **list, char *str, char c);

int open_error(char *path, char *msg);

#endif /* !GIANTMAN_H_ */
