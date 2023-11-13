#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STORAGE_CAPACITY_GB 40
#define MAX_USERS 100
#define MAX_FILES 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_FILENAME_LENGTH 100

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct File {
    char filename[MAX_FILENAME_LENGTH];
    int size;
};

struct User users[MAX_USERS];
int userCount = 0;

struct File files[MAX_FILES];
int fileCount = 0;

void addUser(const char* username, const char* password) {
    if (userCount < MAX_USERS) {
        strncpy(users[userCount].username, username, MAX_USERNAME_LENGTH - 1);
        strncpy(users[userCount].password, password, MAX_PASSWORD_LENGTH - 1);
        users[userCount].username[MAX_USERNAME_LENGTH - 1] = '\0'; // Ensure null-terminated
        users[userCount].password[MAX_PASSWORD_LENGTH - 1] = '\0';
        userCount++;
        printf("User %s added.\n", username);
    } else {
        printf("User database is full.\n");
    }
}

int authenticateUser(const char* username, const char* password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1; // Authentication successful
        }
    }
    return 0; // Authentication failed
}

void addFile(const char* filename, int size) {
    if (fileCount < MAX_FILES) {
        strncpy(files[fileCount].filename, filename, MAX_FILENAME_LENGTH - 1);
        files[fileCount].filename[MAX_FILENAME_LENGTH - 1] = '\0'; // Ensure null-terminated
        files[fileCount].size = size;
        fileCount++;
        printf("File %s added.\n", filename);
    } else {
        printf("File storage is full.\n");
    }
}

int main() {
    printf("NAS Simulation\n");

    printf("Storage Capacity: %d GB\n", STORAGE_CAPACITY_GB);

    addUser("admin", "password123");
    addUser("user1", "pass456");

    if (authenticateUser("admin", "password123")) {
        printf("Authentication successful.\n");
        addFile("example.txt", 100);
        addFile("test.doc", 200);
    } else {
        printf("Authentication failed.\n");
    }

    return 0;
}

