#ifndef HEADER_H
#define HEADER_H

#define MAX_PATH 255
#define BUF_SIZE 1024
#define FILE_SERVER 243
#define GET 1
#define POST 2
#define OK 0
#define E_BAD_OPCODE -1
#define E_BAD_PARAM -2
#define E_IO -3

struct mensaje{
    long source;
    long dest;
    long opcode;
    long count;
    long offset;

    long extra_1;
    long extra_2;
    long result;
    char name[MAX_PATH];
    char data[BUF_SIZE];
};
#endif