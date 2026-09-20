#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 50 

int main(void) {
    FILE *src = fopen("/home/flag05/.flag", "r");
    if (src == NULL) {
        perror("Failed to open src file");
        return EXIT_FAILURE;
    }

    FILE *dest = fopen("/tmp/flag05", "w");
    if (dest == NULL) {
        perror("Failed to open dst file");
        fclose(src);
        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    bytes_read = fread(buffer, sizeof(char), sizeof(buffer), src);
    size_t bytes_written = fwrite(buffer, sizeof(char), bytes_read, dest);
    if (bytes_written < bytes_read) {
	perror("Failed to copy file");
        fclose(src);
        fclose(dest);
        return EXIT_FAILURE;
    }

    printf("Succeeded to copy file\n");

    fclose(src);
    fclose(dest);
    return 0;
}
