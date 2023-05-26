#include "simple_shell.h"

/**
 * read_command - Reads a command from the user
 * @buff: Buffer to store the command
 * @size: Size of the buffer
 * Return: Number of characters read
 */
ssize_t read_command(char *buff, size_t size)
{
        ssize_t read = getline(&buff, &size, stdin);

        if (read == -1)
        {
                if (feof(stdin))
                {
                        write(1, "\n", 1);
                        exit(EXIT_SUCCESS);
                }
                else
		{
                        perror("read_command");
                        exit(EXIT_FAILURE);
                }
        }

        if (read > 0 && buff[read - 1] == '\n')
                buff[read - 1] = '\0';

        return (read);
}
