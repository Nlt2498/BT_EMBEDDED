/*
* File: readnumber.c
* Author: Nguyen Thanh
* Date: 31/03/2023
* Description: This is a file enter a number to convert to texts
*/

#include <stdio.h>
#include <string.h>

char *ones[] = {"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};
char *tens[] = {"", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
char *teens[] = {"ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
char *thousands[] = {"", "thousand ", "million ", "billion "};

void convert_number(int num, char *output) {
    if (num == 0) {
        output = "zero";
        return;
    }
    int negative = 0;
    if (num < 0) {
        negative = 1;
        num = -num;
    }
    int i = 0;
    while (num > 0) {
        if (num % 1000 != 0) {
            int temp = num % 1000;
            if (temp >= 100) {
                sprintf(output, "%s%s%s", ones[temp / 100], "hundred ", temp % 100 != 0 ? "and " : "");
            }
            if (temp % 100 < 20 && temp % 100 >= 10) {
                sprintf(output, "%s%s", output, teens[temp % 10]);
            } else {
                sprintf(output, "%s%s%s", output, tens[(temp % 100) / 10], ones[temp % 10]);
            }
            sprintf(output, "%s%s", output, thousands[i]);
        }
        num /= 1000;
        i++;
    }
    if (negative) {
        sprintf(output, "negative %s", output);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    char output[1000];
    convert_number(num, output);
    printf("%s\n", output);
    return 0;
}