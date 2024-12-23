#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char* decode(const char* message_file) {
    FILE *file = fopen(message_file, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char *pyramid[100]; // Assuming a maximum of 100 lines in the file
    char line[256]; // Assuming maximum line length of 255 characters
    int count = 0;

    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " ");
        token = strtok(NULL, " "); // Skip the number
        pyramid[count] = strdup(token);
        count++;
    }
    fclose(file);

    // Construct the decoded message
    char *decoded_message = (char*)malloc(1000 * sizeof(char)); // Assuming max length of 1000 characters
    decoded_message[0] = '\0'; // Initialize as empty string

    for (int i = 0; i < count; i++) {
        strcat(decoded_message, pyramid[i]);
        strcat(decoded_message, " ");
    }

    return decoded_message;
}

int main() {
    const char* message_file = "test.txt";
    char* decoded_message = decode(message_file);
    if (decoded_message != NULL) {
        printf("Decoded message: %s\n", decoded_message);
        free(decoded_message);
    }
    return 0;
}
