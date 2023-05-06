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

}Personal_Belongings; 

void Add_To_Cart(uint8_t *cart, Personal_Belongings item_name){
   *cart |= item_name;    
}
 
void Remove_From_Cart(uint8_t *cart, Personal_Belongings item_name){
   *cart &= ~item_name; 
}

void Check_The_Product(uint8_t cart, Personal_Belongings item_name){
    cart = cart & item_name;
    
    for(int i=0; i<8; i++)
    {
        if((cart & (1<<i)) != 0){
            switch (i)
            {
            case 0:
                printf(" SHIRT already exists in cart\n");
                break;
            case 1:
                printf(" PANT already exists in cart\n");
                break;
            case 2:
                printf(" SKIRT already exists in cart\n");
                break;
            case 3:
                printf(" DRESS already exists in cart\n");
                break;
            case 4:
                printf(" RING already exists in cart\n");
                break;
            case 5:
                printf(" BRACELET already exists in cart\n");
                break;
            case 6:
                printf(" SHOE already exists in cart\n");
                break;
            case 7:
                printf(" BAG already exists in cart\n");
                break;
            default:
                break;
        }}
        if(~(cart | ~(1<<i)) == (item_name & (1 << i)))
        {
            switch (i)
            {
            case 0:
                printf(" SHIRT not already exists in cart\n");
                break;
            case 1:
                printf(" PANT not already exists in cart\n");
                break;
            case 2:
                printf(" SKIRT not already exists in cart\n");
                break;
            case 3:
                printf(" DRESS not already exists in cart\n");
                break;
            case 4:
                printf(" RING not already exists in cart\n");
                break;
            case 5:
                printf(" BRACELET not already exists in cart\n");
                break;
            case 6:
                printf(" SHOE not already exists in cart\n");
                break;
            case 7:
                printf(" BAG not already exists in cart\n");
                break;
            default:
                break;
        }}
    }

}

void SHOW(uint8_t cart){
    
    printf("Cart includes: \n");
    printf("Number\t  Name\n");
    
    for(int i=0; i<8; i++)
    {
        if((cart & (1<<i)) != 0){
            switch (i)
            {
            case 0:
                printf("%d\t SHIRT\n",i);
                break;
            case 1:
                printf("%d\t PANT\n",i);
                break;
            case 2:
                printf("%d\t SKIRT\n",i);
                break;
            case 3:
                printf("%d\t DRESS\n",i);
                break;
            case 4:
                printf("%d\t RING\n",i);
                break;
            case 5:
                printf("%d\t BRACELET\n",i);
                break;
            case 6:
                printf("%d\t SHOE\n",i);
                break;
            case 7:
                printf("%d\t BAG\n",i);
                break;
            default:
                break;
        }}
    }
}


int main(int argc, char const *argv[])
{
    /* code */
    uint8_t CART; //1 byte 0bxxxxxxxx
    Add_To_Cart(&CART, PANT|SKIRT|DRESS|BRACELET|RING|BAG|SHOE);
    //Remove_From_Cart(&CART, SHIRT|PANT);
    Check_The_Product(CART, SHIRT|PANT|SKIRT|DRESS);
    printf("================================\n");
    SHOW(CART);
    return 0;
}
