#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define	BUFFERSIZE 1000
static int idx = 0;


int main()
{
    char buffer[BUFFERSIZE + 1];

    int fd = 0;


    fd = open("a.txt", O_RDONLY);

    printf("fd values is : %d\n", fd);
    memset(buffer, 1, BUFFERSIZE + 1);
    int rdchar = 1;


    while (rdchar != 0)
    {
        rdchar = read(fd, &buffer[idx], 1);
        idx++;
    }
    printf ("\nidx%d\n", idx);
    buffer[idx] = '\0';
    printf("result\n");
    printf("%s", buffer);

}