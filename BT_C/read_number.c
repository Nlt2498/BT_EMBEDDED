#include <stdio.h>
#include <string.h>

char *numberStrings[] = {"KHONG", "MOT", "HAI", "BA", "BON", "NAM", "SAU", "BAY", "TAM", "CHIN"};
char *tenStrings[] = {"MUOI", "HAI MUOI", "BA MUOI", "BON MUOI", "NAM MUOI", "SAU MUOI", "BAY MUOI", "TAM MUOI", "CHIN MUOI"};
char *hundredString = "TRAM";
char *thousandString = "NGIN";
char *millionString = "TRIEU";
char *billionString = "TY";

void readNumber(int number){
    
    int temp, billion, million, thousand, hundred, ten, ones;
    billion = number / 1000000000;
    temp = number % 1000000000;
    million = temp / 1000000;
    temp %= 1000000;
    thousand = temp / 1000;
    temp %= 1000;
    hundred = temp / 100;
    temp %= 100;
    ten = temp / 10;
    ones = temp % 10;
    
   
    if (million > 0) {
        if (million == 1) {
            printf("MOT TRIEU ");
        } else {
            printf("%s TRIEU ", numberStrings[million]);
        }
    }
    
    if (thousand > 0) {
        if (thousand == 1) {
            printf("MOT NGIN ");
        } else {
            printf("%s %s ", numberStrings[thousand], thousandString);
        }
    }
    
    if (hundred > 0) {
        printf("%s %s ", numberStrings[hundred], hundredString);
    }
    
    if (ten > 0 || ones > 0) {
        if (ten == 0 && ones > 0) {
            printf("%s", numberStrings[ones]);
        } else if (ten == 1 && ones > 0) {
            printf("%s %s", tenStrings[0], numberStrings[ones]);
        } else if (ten > 1 && ones == 0) {
            printf("%s", tenStrings[ten-1]);
        } else if (ten > 1 && ones > 0) {
            printf("%s %s", tenStrings[ten-1], numberStrings[ones]);
        } else {
            printf("%s", tenStrings[ten-1]);
        }
    }
    
    printf(".\n");
}

int main() {
    int number;
    do
    {
        printf("Input number: ");
        scanf("%d", &number);
    }while (number < 0 || number > 999999999); 
    readNumber(number);    
    return 0;
}
