#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        _exit(1);
    }

    const char* source_file = argv[1];
    const char* destination_file = argv[2];

    int fd = open(source_file, O_RDONLY);

    int fd2 = open(destination_file, O_WRONLY | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP);

    char buffer[32];
    size_t bytes;
    while ((bytes = read(fd, buffer, 32)) > 0)
    {
        write(fd2, buffer, bytes);
    }

    close(fd);
    close(fd2);

    return 0;
}