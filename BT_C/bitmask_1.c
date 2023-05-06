/*
* File: bistmask.c
* Author: Nguyen Thanh
* Date: 31/3/2023
* Description: This is a file application bistmask
*/

#include<stdio.h>
#include<stdint.h>

typedef enum{
    SHIRT      = 1 << 0,  //0b00000001
    PANT       = 1 << 1,  //0b00000010
    SKIRT      = 1 << 2,  //0b00000100
    DRESS      = 1 << 3,  //0b00001000
    RING       = 1 << 4,  //0b00010000
    BRACELET   = 1 << 5,  //0b00100000
    SHOE       = 1 << 6,  //0b01000000
    BAG        = 1 << 7   //0b10000000

}PersonalBelongings; 

char *individualItems[] = {"SHIRT","PANT","SKIRT","DRESS","RING","BRACELET","SHOES","BAG"}; //array for printing

/*
* Function: addToCart
* Description: This function add items to cart
* Input:
* cart - a pointer uint8_t 
* itemName - a variable enum Personal_Belongings 
*/
void addToCart(uint8_t *cart, PersonalBelongings itemName){
   *cart |= itemName;    
}

/*
* Function: removeFromCart
* Description: This function remove items to cart
* Input:
* cart - a pointer uint8_t 
* itemName - a variable enum Personal_Belongings 
*/
void removeFromCart(uint8_t *cart, PersonalBelongings itemName){
   *cart &= ~itemName; 
}

/*
* Function: checkItems
* Description: This function check items to cart
* Input:
* cart - a pointer uint8_t 
* itemName - a variable enum Personal_Belongings 
*/
void checkItems (uint8_t cart, PersonalBelongings itemName){

    for(int i = 0; i < 8; i++)
    {
        if(itemName & (1 << i))
        {
            if(cart & (1 << i))
            {
                printf("THE CART HAS : %s\n", individualItems[i]);
            }
            else
            {
                printf("THE CART HASN'T : %s\n", individualItems[i]);  
            }              
        }
    }
}

/*
* Function: showCart
* Description: This function show items in cart
* Input:
* cart - a variable uint8_t  
*/
void showCart (uint8_t cart){

    printf( "THE CART INCLUDES : ");
    
    for(int i = 0; i < 8; i++)
    {
        if(cart & (1 << i))
        {
            printf("%s ", individualItems[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    uint8_t CART; //1 byte 0bxxxxxxxx
    addToCart(&CART, SHIRT|PANT|SKIRT|DRESS|BRACELET|RING|BAG|SHOE);
    removeFromCart(&CART, SHIRT|PANT);
    checkItems(CART, SHIRT|PANT|SKIRT|DRESS);
    printf("================================\n");
    showCart(CART);
    return 0;
}



