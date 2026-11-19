#include <stdio.h>
#include <string.h>

int main(void) {
    char first[200], second[200], result[400];
    int choice;

    printf("Enter a string: ");
    fgets(first, sizeof(first), stdin);
    first[strcspn(first, "\n")] = '\0';

    do {
        printf("\n--- String Operations ---\n");
        printf("1. Find length\n");
        printf("2. Copy string\n");
        printf("3. Concatenate strings\n");
        printf("4. Compare strings\n");
        printf("5. Reverse string\n");
        printf("6. Convert to uppercase\n");
        printf("7. Convert to lowercase\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Length: %zu\n", strlen(first));
                break;

            case 2:
                strcpy(result, first);
                printf("Copied string: %s\n", result);
                break;

            case 3:
                printf("Enter another string: ");
                fgets(second, sizeof(second), stdin);
                second[strcspn(second, "\n")] = '\0';

                strcpy(result, first);
                strcat(result, second);
                printf("Concatenated string: %s\n", result);
                break;

            case 4:
                printf("Enter another string: ");
                fgets(second, sizeof(second), stdin);
                second[strcspn(second, "\n")] = '\0';

                if (strcmp(first, second) == 0)
                    printf("The strings are equal.\n");
                else
                    printf("The strings are not equal.\n");
                break;

            case 5:
                strcpy(result, first);
                for (size_t i = 0, j = strlen(result) - 1;
                     i < j; i++, j--) {
                    char temp = result[i];
                    result[i] = result[j];
                    result[j] = temp;
                }
                printf("Reversed string: %s\n", result);
                break;

            case 6:
                strcpy(result, first);
                for (size_t i = 0; result[i] != '\0'; i++) {
                    if (result[i] >= 'a' && result[i] <= 'z')
                        result[i] -= 'a' - 'A';
                }
                printf("Uppercase string: %s\n", result);
                break;

            case 7:
                strcpy(result, first);
                for (size_t i = 0; result[i] != '\0'; i++) {
                    if (result[i] >= 'A' && result[i] <= 'Z')
                        result[i] += 'a' - 'A';
                }
                printf("Lowercase string: %s\n", result);
                break;

            case 0:
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}