#include <stdio.h>
#include <stdlib.h>

void createFile() {
    char filename[100];
    FILE *file;
    printf("Enter the filename: ");
    scanf("%s", filename);
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to create file.\n");
    } else {
        printf("File created successfully.\n");
        fclose(file);
    }
}

void deleteFile() {
    char filename[100];
    int status;
    printf("Enter the filename: ");
    scanf("%s", filename);
    status = remove(filename);
    if (status == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Failed to delete file.\n");
    }
}

void modifyFile() {
    char filename[100];
    char content[1000];
    FILE *file;
    printf("Enter the filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Failed to open file.\n");
    } else {
        printf("Enter the new content (up to 1000 characters): ");
        scanf(" %[^\n]s", content);
        fprintf(file, "%s", content);
        printf("File modified successfully.\n");
        fclose(file);
    }
}

int main() {
    int choice;
    while (1) {
        printf("File Management System\n");
        printf("1. Create a file\n");
        printf("2. Delete a file\n");
        printf("3. Modify a file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                deleteFile();
                break;
            case 3:
                modifyFile();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}
