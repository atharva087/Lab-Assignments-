#include <stdio.h>

int main(void) {
    char sourceName[256];
    char destinationName[256];
    FILE *source;
    FILE *destination;
    int ch;

    printf("Enter the source file name: ");
    if (scanf("%255s", sourceName) != 1) {
        fprintf(stderr, "Invalid source file name.\n");
        return 1;
    }

    printf("Enter the destination file name: ");
    if (scanf("%255s", destinationName) != 1) {
        fprintf(stderr, "Invalid destination file name.\n");
        return 1;
    }

    source = fopen(sourceName, "rb");
    if (source == NULL) {
        perror("Could not open source file");
        return 1;
    }

    destination = fopen(destinationName, "wb");
    if (destination == NULL) {
        perror("Could not open destination file");
        fclose(source);
        return 1;
    }

    while ((ch = fgetc(source)) != EOF) {
        if (fputc(ch, destination) == EOF) {
            perror("Error writing to destination file");
            fclose(source);
            fclose(destination);
            return 1;
        }
    }

    if (ferror(source)) {
        perror("Error reading source file");
        fclose(source);
        fclose(destination);
        return 1;
    }

    if (fclose(source) != 0) {
        perror("Error closing source file");
        fclose(destination);
        return 1;
    }

    if (fclose(destination) != 0) {
        perror("Error closing destination file");
        return 1;
    }

    printf("File contents copied successfully.\n");
    return 0;
}