/* CS261- Recitation 1 - Q.2
 * Solution description: call the function foo using "reference" to see the values before and after the function
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = *a * 2;

    /*Set b to half its original value*/
    *b = *b / 2;

    /*Assign a+b to c*/
    c = *a + *b;

    /*Return c*/

     
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 7, 8, 9 respectively*/
    int x = 7;
    int y = 8;
    int z = 9;
    
    /*Print the values of x, y and z*/
    printf("%d\n", x);
    printf("%d\n", y);
    printf("%d\n", z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
    foo(&x, &y, z);

    /*Print the value returned by foo*/
    printf("%d\n", foo(&x, &y, z));

    /*Print the values of x, y and z again*/
    printf("%d\n", x);
    printf("%d\n", y);
    printf("%d\n", z);

    /*Is the return value different than the value of z?  Why? */

    /* Yes, the return value is different than z because of the multiplication
        and addition that is done inside foo()*/
    return 0;
}
    
    
