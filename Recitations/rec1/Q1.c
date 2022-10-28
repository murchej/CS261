/* CS261- Recitation 1 - Q. 1*
 * Solution description: check the properties, like value and address, of pointer
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     printf("value of iptr : %d\n", *iptr);
     
     /*Print the address pointed to by iptr*/
     printf("Address pointed to by iptr: %p", iptr);

     /*Print the address of iptr itself*/
     printf("Address of iptr: %p", &iptr);
}

int main(){

    int x = 0;

    printf("%p", &x);

    fooA(&x);

    printf("%d", x);

    
    /*declare an integer x and initialize it with 0*/
    
    /*print the address of x*/
    
    /*Call fooA() with the address of x*/
    
    /*print the value of x*/

    return 0;
}
