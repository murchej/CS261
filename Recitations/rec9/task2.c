#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * return true (1) if n is happy, false (0) otherwise
 */
bool isHappy (int n){

	if(n == 1 || n == 7)
    
	return true;
          
    int nsum = n;
	
	int x = n;
  
    while(nsum > 9){
        
		nsum = 0;
          
    while(x > 0){
            
		int y = x % 10;
       
	    nsum += y * y;
       
	    x /= 10;
    }
        
	if(nsum == 1)
        
		return true;
              
        x = nsum;
    }
    
	if(nsum == 7)
        
	return true;
          
   
    return false;

}


int squareSum(int n){

	int squaresum = 0;

	while(n){

		squaresum += (n % 10) * (n % 10);

		n /= 10;

		return squaresum;
	}
}

/*
 * Below are testing functions... DO NOT MODIFY!!!
 */

void show_result(int e, int r){
	printf("Expected: %d\nActual: %d...", e, r);
	if (r != e) 
        printf("FAIL\n\n\n");
    else 
        printf("OK\n\n\n");
}



int main()
{
	printf("\nTEST 1...19\n");
	show_result(1, isHappy(19));

	printf("\nTEST 2...2\n");
	show_result(0, isHappy(2));

	printf("\nTEST 3...7\n");
	show_result(1, isHappy(7));

	printf("\nTEST 4...176\n");
	show_result(1, isHappy(176));

	printf("\nTEST 5...36\n");
	show_result(0, isHappy(36));

	

	return 0;
}
