#define PROG_NAME_LENGTH 128
#define COMMENT_LENGTH 156
#define COREWAR_EXEC_MAGIC 0xea83f3

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct      s_header
{
    unsigned char   prog_name[5];
    unsigned char   comment[8];
}                   t_header;

int     main(void)
{
    t_header    strings;
    unsigned char *out;
    int         fd;

    fd = open("test", O_RDWR);
    strings.comment[0] = 'C';
    strings.comment[1] = 'o';
    strings.comment[2] = 'm';
    strings.comment[3] = 'm';
    strings.comment[4] = 'e';
    strings.comment[5] = 'n';
    strings.comment[6] = 't';
    strings.comment[7] = '\0';
    strings.prog_name[0] = 'N';
    strings.prog_name[1] = 'a';
    strings.prog_name[2] = 'm';
    strings.prog_name[3] = 'e';
    strings.prog_name[4] = '\0';
    out = encode_output(&strings, 25);
    write(fd, out, (16 + PROG_NAME_LENGTH + COMMENT_LENGTH));
    return (0);
}