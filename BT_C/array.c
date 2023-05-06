#include <stdio.h>
#include <stdint.h>

uint8_t arr[] = {1, 7, 9, 3, 7, 1, 2, 6, 7, 8, 2, 9, 9, 3};

void sortDescending(){
    uint8_t temp;
    for(int i = 0; i < sizeof(arr) - 1 ; i++){
        for(int j = i+1; j < sizeof(arr); j++){
            if(arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        printf(" %d ", arr[i]);

    }
}

void countElementInArray()
{
    int count = 1;
    for(int i = 0; i < sizeof(arr); i++){
        if (arr[i] == arr[i+1])
        {
            count++;
        }else{
            printf("\nElement %d appear in the array %d times", arr[i], count);
            count = 1;
        }
    }
}

int main(int argc, char const *argv[])
{
    sortDescending();
    countElementInArray();
    return 0;
}

