#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define BUFFER_SIZE 1024

int copyStdinToStdout()
{
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    int ec = 0;

    while ((bytes_read = read(0, buffer, sizeof(buffer))) > 0)
    {
        if (write(1, buffer, bytes_read) != bytes_read)
        {
            ec = 4;
            break;
        }
    }

    if (bytes_read < 0)
    {
        ec = 3;
    }

    return ec;
}

int copyStdinToFile(const char *destinationPath)
{
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    int ec = 0;
    int destinationFile = open(destinationPath, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (destinationFile == -1)
    {
        ec = 4;
    }
    else
    {
        while ((bytes_read = read(0, buffer, sizeof(buffer))) > 0)
        {
            if (write(destinationFile, buffer, bytes_read) != bytes_read)
            {
                ec = 4;
                break;
            }
        }

        if (bytes_read < 0)
        {
            ec = 3;
        }

        close(destinationFile);
    }

    return ec;
}

int copyFileToFile(const char *sourcePath, const char *destinationPath)
{
    int sourceFile = open(sourcePath, O_RDONLY);
    int ec = 0;

    if (sourceFile == -1)
    {
        ec = 3;
    }
    else
    {
        int destinationFile = open(destinationPath, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

        if (destinationFile == -1)
        {
            ec = 4;
        }
        else
        {
            char buffer[BUFFER_SIZE];
            ssize_t bytesRead;

            while ((bytesRead = read(sourceFile, buffer, sizeof(buffer))) > 0)
            {
                if (write(destinationFile, buffer, bytesRead) != bytesRead)
                {
                    ec = 4;
                    break;
                }
            }

            if (bytesRead < 0)
            {
                ec = 3;
            }

            close(destinationFile);
        }

        close(sourceFile);
    }

    return ec;
}

int main(int argc, char *argv[])
{
    if (argc != 5 || strcmp(argv[1], "-i") != 0 || strcmp(argv[3], "-o") != 0)
    {
        return 2;
    }

    int ec = 0;

    if (strcmp(argv[2], "-") == 0 && strcmp(argv[4], "-") != 0)
    {

        ec = copyStdinToStdout();
    }
    else
    {
        ec = copyFileToFile(argv[2], argv[4]);
    }
    return ec;
}
