#include<stdio.h>
#include<string.h>

int main(int argc, char **argv) {
    char file_name[256];

    if (argc == 1) {
        printf("Enter file name: ");
        fflush(stdout);
        fgets(file_name, sizeof(file_name), stdin);
        file_name[strcspn(file_name, "\n")] = 0;
    } else {
        strcpy(file_name, argv[1]);
    }

    FILE *ptr;
    ptr = fopen(file_name, "r");

    if(ptr == NULL) {
        printf("Sorry the file doesn't exist!\n");
        return 1;
    } else {
        int num;
        fscanf(ptr, "%d", &num);
        printf("The value of num is %d\n", num);
        fclose(ptr);
        return 0;
    }
}

