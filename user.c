#include "user.h"
#include <stdio.h>
#include <string.h>




void loginUser(const char *username, const char *password, int *loggedIn) {
    FILE *file = fopen("users.txt", "r");
    if (!file) {
        printf("Error opening user data file.\n");
        return;
    }

    char line[256];
    *loggedIn = 0;
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        char *fileUsername = strtok(line, ",");
        char *filePassword = strtok(NULL, ",");

        if (fileUsername && filePassword && strcmp(username, fileUsername) == 0 && strcmp(password, filePassword) == 0) {
            *loggedIn = 1;
            break;
        }
    }
    fclose(file);

    if (*loggedIn) {
        printf("Login successful!\n");
    } else {
        printf("Login failed: Incorrect username or password.\n");
    }
}


void createAccount(const char *username, const char *password) {
    FILE *file = fopen("users.txt", "a+");
    if (!file) {
        printf("Error opening user data file.\n");
        return;
    }

    rewind(file);
    char line[256];
    int exists = 0;
    while (fgets(line, sizeof(line), file)) {
        char *fileUsername = strtok(line, ",");
        if (fileUsername && strcmp(username, fileUsername) == 0) {
            printf("Account creation failed: Username already exists.\n");
            exists = 1;
            break;
        }
    }

    if (!exists) {
        fprintf(file, "%s,%s\n", username, password);
        printf("Account created successfully!\n");
    }
    fclose(file);
}
