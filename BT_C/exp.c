/*
* File: string_reverse.c
* Author: Nguyen Thanh
* Date: 31/3/2023
* Description: This is a file reverse the string
*/

#include <stdio.h>
#include <string.h>

char Arr[] = {"Make no mistake. All your attempts to create a chilling effect, a throttling effect, a strangulating effect on open fearless speech relating to public influence will not stop either Rahul Gandhi or the Congress Party"};

/*
* Function: reverse
* Description: This function reverses the characters in a part of a string, from the first to the last position passed through two pointers
* Input:
* begin - a pointer char 
* end - a pointer char 
* Output: No 
*/
void reverse(char *begin, char *end) {
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

/*
* Function: reverseWords
* Description: This function use the reverse function to reverse the words in the string and then reverse the whole string
* Input:
* text - a pointer char 
* Output: No 
*/
void reverseWords(char *text) {
    char *word_begin = NULL;
    char *temp = text; 
    while (*temp) {
        // Tim đến vị trí bắt đầu của từ
        if ((word_begin == NULL) && (*temp != ' ')) {
            word_begin = temp;
        }
        // Tìm đến vị trí kết thúc của từ
        if (word_begin && ((*(temp + 1) == ' ') || (*(temp + 1) == '\0'))) {
            reverse(word_begin, temp);
            word_begin = NULL;
        }
        temp++;
    }
    reverse(text, temp - 1); // Đảo ngược lại toàn bộ chuỗi
}

int main(int argc, char const *argv[])
{
    reverseWords(Arr);
    printf("After string reverse:\n");
    printf("%s\n", Arr);
    return 0;
}

