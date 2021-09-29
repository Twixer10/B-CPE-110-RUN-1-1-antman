/*
** EPITECH PROJECT, 2021
** ANTMAN
** File description:
** antman
*/

#ifndef ANTMAN_H_
#define ANTMAN_H_

#include "./my.h"
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define UNUSED __attribute__((unused))

typedef struct lyric_h
{
    char *word;
    int i;
    int indx;
    struct lyric_h *next;
} lyric_t;

int compress_1(char *path);
int step_one_lyric(char **str);
lyric_t *create_node(char *str);
lyric_t *get_node(lyric_t **list, char *str);
void push_last_in_list(lyric_t **list, char *str);

int open_error(char *path, char *msg);

#endif /* !ANTMAN_H_ */
