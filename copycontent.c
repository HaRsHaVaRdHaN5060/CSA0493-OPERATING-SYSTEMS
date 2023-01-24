#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int source_fd, target_fd, n;
    char buffer[4096];

  
    if (argc != 3) {
        printf("Usage: %s <source file> <target file>\n", argv[0]);
        return 1;
    }


    source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) {
        perror("Error opening source file");
        return 1;
    }

    target_fd = open(argv[2], O_WRONLY | O_CREAT, 0644);
    if (target_fd == -1) {
        perror("Error opening/creating target file");
        return 1;
    }

\    while ((n = read(source_fd, buffer, sizeof(buffer))) > 0) {
        if (write(target_fd, buffer, n) != n) {
            perror("Error writing to target file");
            return 1;
        }
    }

    close(source_fd);
    close(target_fd);

    return 0;
}
