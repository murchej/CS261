#include <stdio.h>
#include <stdlib.h>

void
f(void)
{
    int a[4];
    int *b = malloc(16);
    int *c;
    int i;

    printf("1: a = %p, b = %p, c = %p\n", a, b, c); // a) I got this output because of the pointers in the print statement, 
                                                    //     and they represent the memory address of those pointers.
                                                    // b)  a = 0x7ffdb031b320, b = 0x7ffdb031b324, c = 0x7ffdb031b321
                                            
                                                    // c)    a = 0x7ffdb031b320, b = 0x7ffdb031b324, c = 0x7ffdb031b321
    c = a;
    for (i = 0; i < 4; i++)
	a[i] = 100 + i;
    c[0] = 200;
    printf("2: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n", // a) I got this output because of the arithmetic in the for loop adding the different numbers
                                                              //       in the array.
                                                                //  b)   a = 0x7ffdb031b320, b = 0x7ffdb031b324, c = 0x7ffdb031b321
                                                                //  c)   a = a[0] = 200, a[1] = 101, a[2] = 102, a[3] = 103, b = 0x7ffdb031b324 , c = 200
                                                                
	   a[0], a[1], a[2], a[3]);

    c[1] = 300;
    *(c + 2) = 301;
    3[c] = 302;
    printf("3: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n", // a) We got this output because the arithmetic that manipulated c
                                                              // b) a = 0x7ffdb031b320, b = 0x7ffdb031b324, c = 0x7ffdb031b321
                                                              // c) a = a[0] = 200, a[1] = 300, a[2] = 301, a[3] = 302, b = 0x7ffdb031b324, c = 302
	   a[0], a[1], a[2], a[3]);

    c = c + 1;
    *c = 400;
    printf("4: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n", // a) we got this output because of the arithmetic done on c
                                                                // b) a = 0x7ffdb031b320, b = 0x7ffdb031b324, c = 0x7ffdb031b321
                                                                // c) a = a[0] = 200, a[1] = 400, a[2] = 301, a[3] = 302, b = 0x7ffdb031b324, c = 400
	   a[0], a[1], a[2], a[3]);

    c = (int *) ((char *) c + 1);
    *c = 500;
    printf("5: a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n", // a) The use of char and pointer c let us get this output
                                                              // b)  a = 0x7ffdb031b320, b = 0x7ffdb031b324, c = 0x7ffdb031b321
	   a[0], a[1], a[2], a[3]);                                // c) a[0] = 200, a[1] = 128144, a[2] = 256, a[3] = 302, b = 0x7ffdb031b324, c = 0x7ffe53784fa1

    b = (int *) a + 1;
    c = (int *) ((char *) a + 1);
    printf("6: a = %p, b = %p, c = %p\n", a, b, c);             // a) we got this output from print the address of the pointers
                                                                // b) a = 0x7ffe53784fa0, b = 0x7ffe53784fa4, c = 0x7ffe53784fa1
                                                                // c) a = 0x7ffe53784fa0, b = 0x7ffe53784fa4, c = 0x7ffe53784fa1
}

int
main(int ac, char **av)
{
    f();
    return 0;
}
