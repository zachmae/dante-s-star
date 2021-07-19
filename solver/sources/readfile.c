/*
** EPITECH PROJECT, 2021
** readfile
** File description:
** readfile
*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "solver.h"

static char *get_buff(int fd, struct stat info)
{
    int size = info.st_size;
    char *buff = malloc(sizeof(char) * size + 1);
    int len = 0;
    int offset = 0;

    while ((len = read(fd , buff + offset, size - offset)) > 0) {
        offset = offset + len;
    }
    if (offset == 0) {
        fprintf(stderr, "ERROR: empty file\n");
        exit(84);
    }
    buff[offset] = '\0';
    return (buff);
}

char *read_file(char const *filename)
{
    int fd = open(filename, O_RDONLY);
    struct stat info;
    char *buff;

    if (fd == -1) {
        fprintf(stderr, "ERROR: file does not exist.\n");
        exit(84);
    }
    stat(filename, &info);
    buff = get_buff(fd, info);
    close(fd);
    return buff;
}
