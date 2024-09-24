#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[] = "Amrit";
    char text[] = "Hello, this is a test file.\n";
    char buffer[255];

    /* Create and write to the file */
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return EXIT_FAILURE;
    }

    fprintf(file, "%s", text);
    fclose(file);

    /* Read from file */
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return EXIT_FAILURE;
    }

    printf("Reading from file:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer); // Print each line
    }

    fclose(file);

    return EXIT_SUCCESS;
}

