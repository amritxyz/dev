#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <text>\n", argv[0]);
        return 1; // return EXIT_FAILURE;
    }

    char *filename = argv[1];
    char *text = argv[2];

    /* Create and write to file */
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    fprintf(file, "%s\n", text);
    fclose(file);

    /* Read from file */
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    char buffer[255];
    printf("Reading from file:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);

    return 0;
}

