#include <stdio.h>
#include <string.h>
void characterStuffing();
int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Character Stuffing\n2. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            characterStuffing();
        }
        else if (choice == 2)
        {
            return 0;
        }
        else
        {
            printf("\nInvalid option. Try again.\n");
        }
    }
}
void characterStuffing()
{
    char originalData[50], stuffedData[100];
    int i, j = 6, length;
    char flags[] = "dlestx";
    printf("\nEnter the number of characters: ");
    scanf("%d", &length);
    getchar();
    printf("\nEnter the characters: ");
    for (i = 0; i < length; i++)
    {
        scanf("%c", &originalData[i]);
    }
    printf("\nOriginal Data: ");
    for (i = 0; i < length; i++)
    {
        printf("%c", originalData[i]);
    }
    strcpy(stuffedData, flags);
    for (i = 0; i < length; i++)
    {
        if (originalData[i] == 'd' && originalData[i + 1] == 'l' && originalData[i + 2] == 'e')
        {
            strcpy(&stuffedData[j], "dle");
            j += 3;
        }
        stuffedData[j++] = originalData[i];
    }
    strcat(stuffedData, "dleetx");
    printf("\nTransmitted Data: %s", stuffedData);
}
