/*
* File: sum_sortstring.c
* Author: Nguyen Thanh
* Date: 4/4/2023
* Description: This is a file sum the numbers entered and sort the characters and strings alphabetically
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

/*
* Function: inputData
* Description: This function take the input value and save it in an array
* Input:
* num - a array double 
* str - a array 2D char 
* indexNum - a variable int
* indexStr - a variable int 
* Output: No
*/
void inputData(double num[MAX], char str[MAX][MAX], int *indexNum, int *indexStr) {
    int option;
    char key;

    while (1) {
        printf("Press 1 to select real number\n");
        printf("Press 2 to select an integer\n");
        printf("Press 3 to select characters\n");
        printf("Press 4 to select string\n");
        printf("Please choose: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter real number: ");
                scanf("%lf", &num[*indexNum]);
                (*indexNum)++;
                break;
            case 2:
                printf("Enter integer: ");
                scanf("%lf", &num[*indexNum]);
                (*indexNum)++;
                break;
            case 3:
                printf("Enter characters: ");
                scanf(" %c", &key);
                str[*indexStr][0] = key;
                str[*indexStr][1] = '\0';
                (*indexStr)++;
                break;
            case 4:
                printf("Enter string: ");
                scanf("%s", str[*indexStr]);
                (*indexStr)++;
                break;
            default:
                printf("Invalid. Please choose again.\n");
        }

        printf("Continue? (Y/N): ");
        scanf(" %c", &key);
        if (key == 'N' || key == 'n') {
            break;
        }
    }
}

/*
* Function: output
* Description: This function output to the result screen, after processing sum the numbers entered and sort the characters and strings alphabetically
* Input:
* num - a array double 
* str - a array 2D char 
* n  - a variable int
* m - a variable int 
* Output: No
*/
void output(double num[], int indexNum, char str[][MAX], int indexStr) {
    int i;
    double sum = 0;

    if (indexNum > 0) {
        for (i = 0; i < indexNum; i++) {
            sum += num[i];    // Tính tổng các giá trị nhập là số nguyên, số thực
        }
        printf("---------------------\n");
        printf("Sum of numbers: %lf\n", sum);
    }

    if (indexStr > 0) {
        char temp[MAX];
        for (i = 0; i < indexStr - 1; i++) {
            for (int j = i + 1; j < indexStr; j++) {
                if (strcmp(str[i], str[j]) > 0) {
                    strcpy(temp, str[i]);
                    strcpy(str[i], str[j]);
                    strcpy(str[j], temp);
                }
            }
        }

        printf("Character/string values after sorting:\n");
        for (i = 0; i < indexStr; i++) {
            printf("%s\n", str[i]);
        }
    }
}


int main(int argc, char const *argv[])
{
    int indexNum = 0, indexStr = 0;
    double num[MAX];
    char str[MAX][MAX];

    inputData(num, str, &indexNum, &indexStr);
    output(num, indexNum, str, indexStr);
    return 0;
}

/*
void sort_string(char str[MAX][MAX], int m) {
    char temp[MAX];
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }
}
*/