/*
* File: count_string.c
* Author: Nguyen Thanh
* Date: 3/4/2023
* Description: This is a file count the number of occurrences of a word in a sentence
*/

#include <stdio.h>

#define MAX_WORDS 100
#define MAX_LENGTH 100
char sentence[] = "this is a question";

/*
* Function: str_cmp 
* Description: This function compare 2 strings
* Input:
* str1 - a pointer char 
* str2 - a pointer char
* lengthStr - an integer value
* Output:
*   returns 1 if str1 = str2 hoặc ngược lại = 0 
*/
int str_cmp(char *str1, char *str2, int lengthStr) {
    for (int i = 0; i < lengthStr; i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    return 1;
}

/*
* Function: count_words
* Description: This function split words and calculate the number of occurrences of each word
* Input:
* sentence - a pointer char
* words - array 2D
* counts - array
* word_count - an integer value
*/

void count_words(char *sentence, char words[MAX_WORDS][MAX_LENGTH], int counts[MAX_WORDS], int *word_count){
    char *start = sentence;
    char *end = sentence;
    int i, j;

    while (*end != '\0') {
        if (*end == ' ') {
            *end = '\0';
            for (i = 0; i < *word_count; i++) {
                if (str_cmp(words[i], start, end - start)) {
                    counts[i]++;
                    break;
                }
            }
            
            if (i == *word_count) {
                for (j = 0; j < end - start; j++) {
                    words[*word_count][j] = start[j];
                }
                words[*word_count][j] = '\0';
                counts[*word_count] = 1;
                (*word_count)++;
            }
            start = end + 1;
        }
        end++;
    }
    
    
    for (i = 0; i < *word_count; i++) {
        if (str_cmp(words[i], start, end - start)) {
            counts[i]++;
            break;
        }
    }
    if (i == *word_count) {
        for (j = 0; j < end - start; j++) {
            words[*word_count][j] = start[j];
        }
        words[*word_count][j] = '\0';
        counts[*word_count] = 1;
        (*word_count)++;
    } 
}

/*
* Function: print_word_counts
* Description: This function output results
* Input:
* words - array 2D
* counts - array
* word_count - an integer value
*/

void print_word_counts(char words[MAX_WORDS][MAX_LENGTH], int counts[MAX_WORDS], int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i], counts[i]);
    }
}

int main(int argc, char const *argv[])
{
    char words[MAX_WORDS][MAX_LENGTH];
    int counts[MAX_WORDS] = {0};
    int word_count = 0;
    
    count_words(sentence, words, counts, &word_count);
    print_word_counts(words, counts, word_count);

    return 0;
}
