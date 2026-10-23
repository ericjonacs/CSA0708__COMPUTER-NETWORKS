
#include <stdio.h>
#include <string.h>

int main(void)
{
    char data[200], stuffed[420];
    int i, j = 0, count = 0;

    printf("Enter data bits (0s and 1s only): ");
    scanf("%199s", data);

    /* Validate input */
    for (i = 0; data[i] != '\0'; i++)
    {
        if (data[i] != '0' && data[i] != '1')
        {
            printf("Invalid input: enter only 0 and 1.\n");
            return 1;
        }
    }

    /* Opening flag */
    strcpy(stuffed, "01111110");
    j = strlen(stuffed);

    /* Perform bit stuffing */
    for (i = 0; data[i] != '\0'; i++)
    {
        stuffed[j++] = data[i];

        if (data[i] == '1')
        {
            count++;

            if (count == 5)
            {
                stuffed[j++] = '0';
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    /* Closing flag */
    strcpy(stuffed + j, "01111110");

    printf("Original data : %s\n", data);
    printf("Stuffed frame : %s\n", stuffed);

    return 0;
}

