#include <stdio.h>
#include <stdint.h>
#include <string.h>

char Arr[] = {"Make no mistake. All your attempts to create a chilling effect, a throttling effect, a strangulating effect on open fearless speech relating to public influence will not stop either Rahul Gandhi or the Congress Party"};

void stringReverse(){
    int n = sizeof(Arr);
    int i, j = n -1;

    for(int i = n-1; i >=0; i--){
        if(Arr[i] == ' '){
            for(int pos = i+1; pos <=j; pos++)
            printf("Arr[pos]");
            j=i-1;
            printf(" ");
        }
        if(i == 0){
            for(int pos = i; pos <= j; pos++) 
             printf("Arr[pos]");
        }
    }
}


int main(int argc, char const *argv[])
{
    /* code */
    stringReverse();
    return 0;
}
