#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

// Function prototypes
void addCredential();
void viewCredentials();
void deleteCredentials();
void encryptDecrypt(char *data);

int main() {
    int choice;

    while(1) {
        printf("\nPassword Manager Menu:\n");
        printf("1. Add New Credential\n");
        printf("2. View Credentials\n");
        printf("3. Delete Credentials\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCredential();
                break;
            case 2:
                viewCredentials();
                break;
            case 3:
                deleteCredentials();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void addCredential() {
    FILE *file = fopen("credentials.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char website[MAX], username[MAX], password[MAX];

    printf("Enter Website: ");
    scanf("%s", website);
    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);

    // Encrypt the password
    encryptDecrypt(password);

    fprintf(file, "%s %s %s\n", website, username, password);
    fclose(file);

    printf("Credential added successfully!\n");
}

void viewCredentials() {
    FILE *file = fopen("credentials.txt", "r");
    if (file == NULL) {
        printf("No credentials saved yet.\n");
        return;
    }

    char website[MAX], username[MAX], password[MAX];

    printf("\nStored Credentials:\n");
    while (fscanf(file, "%s %s %s", website, username, password) != EOF) {
        // Decrypt the password before displaying
        encryptDecrypt(password);

        printf("Website: %s, Username: %s, Password: %s\n", website, username, password);
    }
    fclose(file);
}

void deleteCredentials() {
    // Simply remove the credentials file
    if (remove("credentials.txt") == 0) {
        printf("All credentials deleted successfully!\n");
    } else {
        printf("No credentials found to delete.\n");
    }
}

// Simple XOR encryption/decryption function
void encryptDecrypt(char *data) {
    char key = 'K'; // Simple XOR key
    for (int i = 0; i < strlen(data); i++) {
        data[i] ^= key;
    }
}