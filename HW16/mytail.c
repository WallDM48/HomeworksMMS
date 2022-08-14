#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define REQUIRED_ARG_COUNT 1

int number_line_count = 10;

static void tail(int input_fileno)
{
    char buffer;
    ssize_t read_count;
    long current_line_count = 0;
    while (current_line_count < number_line_count - 1 && (read_count = read(input_fileno, &buffer, 1)) != 0)
    {
        if (-1 == read_count)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }

        if ('\n' == buffer)
            current_line_count++;
    }

    while ((read_count = read(input_fileno, &buffer, 1)) != 0)
    {
        if (-1 == read_count)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }

        if (-1 == write(STDOUT_FILENO, &buffer, 1))
        {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char **argv)
{
    
    if (argc < REQUIRED_ARG_COUNT + 1)
        exit(EXIT_FAILURE);

    int fd = open(argv[1], O_RDONLY);

        tail(fd);

        close(fd);

    return EXIT_SUCCESS;
}