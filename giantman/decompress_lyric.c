/*
** EPITECH PROJECT, 2021
** B-CPE-110-RUN-1-1-antman-thomas.techer
** File description:
** decompress_lyric
*/

#include "./include/giantman.h"

char *remove_char(char *str)
{
    char *new = malloc(sizeof(char) * my_strlen(str) - 1);
    int i = 0;

    while (i <= my_strlen(str) - 3) {
        new[i] = str[i];
        i++;
    }
    str[i] = '\n';
    return (new);
}

void replace_all(lyric_t **lklst, char *str)
{
    int i = 0;
    char **d = my_strtok(str, ' ');

    lyric_t *tmp = *lklst;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }


    while (d[i]) {
        if (get_node(lklst, d[i][0]) != NULL) {
            my_printf("%s ", get_node(lklst, d[i][0])->word);
        } else {
            my_printf("%s ", d[i]);
        }
        i++;
    }
}

int step_two_lyric(char *str , char *dico)
{
    char **dicos = my_strtok(dico, ',');
    int i = 0;
    lyric_t *lklst = create_node("owo", 'c');

    while (dicos[i]) {
        push_last_in_list(&lklst, remove_char(dicos[i]),
        dicos[i][my_strlen(dicos[i]) - 1]);
        i++;
    }

    replace_all(&lklst, str);
    return (0);
}

int step_one_lyric(char *str)
{
    int i = 0;
    int k = 0;
    char *new;
    char *tmp = str;

    while (str[i]) {
        if (str[i++] != '\n') {
            k++;
            tmp++;
        } else
            break;
    }
    i = 0;
    new = malloc(sizeof(char) * k);
    while (i <= k) {
        new[i] = str[i];
        i += 1;
    }
    new[i] = '\0';
    return (step_two_lyric(tmp, new));
}

int decompress_1(char *path) {
    struct stat st;
    int f = open(path, O_RDONLY);
    char *str;

    if (f == -1)
        return (open_error(path, ": error during opening operation."));
    stat(path, &st);
    str = malloc(sizeof(char) * st.st_size);
    read(f, str, st.st_size);

    step_one_lyric(str);
    close(f);
    return (0);
}