/*
** EPITECH PROJECT, 2021
** B-CPE-110-RUN-1-1-antman-thomas.techer
** File description:
** compress_lyric
*/

#include "./include/antman.h"

int compress_1(char *path)
{
    char **l;
    struct stat st;
    int f = open(path, O_RDONLY);
    char *str;

    if (f == -1)
        return (open_error(path, ": error during opening operation."));
    stat(path, &st);
    str = malloc(sizeof(char) * st.st_size);
    read(f, str, st.st_size);
    l = my_str_to_word_array(str);

    step_one_lyric(l);
    close(f);
    return (0);
}

int is_char2(char *str)
{
    return (my_str_isalpha(str));
}

void write_dico(lyric_t **lklst) {
    lyric_t *tmp = *lklst;

    while (tmp->next != NULL) {
        if (tmp->next != NULL)
            if (tmp->next->i >= 2 && my_strlen(tmp->next->word) >= 3)
                my_printf("%s:%d,", tmp->word, tmp->indx);
        tmp = tmp->next;
    }
    my_putchar('\n');
}

int step_two_lyric(lyric_t **lklst, char **str)
{
    int k = 0;

    write_dico(lklst);
    while (str[k]) {
        if (get_node(lklst, str[k]) == NULL)
            my_printf("%s ", str[k]);
        else {
            if (get_node(lklst, str[k])->i >= 2 &&
            my_strlen(get_node(lklst, str[k])->word) >= 3) {
                my_printf("%d ", (get_node(lklst, str[k])->indx));
            } else
                my_printf("%s ", get_node(lklst, str[k])->word);
        }
        k++;
    }
    return (0);
}

int step_one_lyric(char **str)
{
    lyric_t *lklst = create_node("owo");
    int i = 0;

    while (str[i]) {
        if (my_strcmp(str[i], "")) {
            if (get_node(&lklst, str[i]) == NULL) {
                push_last_in_list(&lklst, str[i]);
            } else {
                get_node(&lklst, str[i])->i += 1;
            }
        }
        i++;
    }
    return (step_two_lyric(&lklst, str));
}