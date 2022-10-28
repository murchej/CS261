#include <stdio.h>
#include <stdlib.h>

int findKthLargest(int* nums, int numsSize, int k)
{
    /*int min[k];

    for(int i = 0; i < k; i++){
        
        min[i] = nums[i];
        minbuild(min, k);

        for(i = k; i < numsSize; i++){

            if(nums[i] > min[0]){

                min[0] = nums[i];

                heapify(min, k, 0);
            }
        }
    }

    return min[0];*/

    for(int i = 0; i < numsSize; i++)
    
    nums[i] = nums[i];   

    build(nums, numsSize);  

    return nums[numsSize - k];   
}


void heapify(int* nums, int numsSize, int k){
    
    int largest = k;    
    
    int l = 2 * k + 1;  
    
    int r = 2 * k + 2;  // right child

    if (l < numsSize && nums[l] > nums[largest])  
        largest = l;    

    if (r < numsSize && nums[r] > nums[largest])

        largest = r;  

    if (largest != k)  
    {
        swap(&nums[k], &nums[largest]);   
        heapify(nums, numsSize, largest);   
    }
}


void build(int* nums, int numsSize){

     for (int i = numsSize / 2 - 1; i >= 0; i--)
        heapify(nums, numsSize, i);     

    for (int i = numsSize - 1; i >= 0; i--)
    {
        swap(&nums[0], &nums[i]);  
        heapify(nums, i, 0);    
    }
}


void swap(int *a, int *b){
   
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main(int argc, char **argv)
{
    
    printf("\nTest 1...\numsSize");
    int num1[6] = {3,2,1,5,6,4};
    printf("2nd largest in [3 2 1 5 6 4]\numsSize");
    printf("Expected: 5\numsSize");
    printf("Actual: %d\numsSize", findKthLargest(num1, 6, 2));

    printf("\nTest 2...\numsSize");
    int num2[9] = {3,2,3,1,2,4,5,5,6};
    printf("4th largest in [3 2 3 1 2 4 5 5 6]\numsSize");
    printf("Expected: 4\numsSize");
    printf("Actual: %d\numsSize", findKthLargest(num2, 9, 4));


    printf("\nTest 3...\numsSize");
    int num3[5] = {10,10,10,10,10};
    printf("5th largest in [10 10 10 10 10]\numsSize");
    printf("Expected: 10\numsSize");
    printf("Actual: %d\numsSize", findKthLargest(num3, 5, 5));

    printf("\nTest 4...\numsSize");
    int num4[7] = {-10,10,-10,10,-10,10,0};
    printf("4th largest in [-10 10 -10 10 -10 10 0]\numsSize");
    printf("Expected: 0\numsSize");
    printf("Actual: %d\numsSize", findKthLargest(num4, 7, 4));

    printf("\nTest 5...\numsSize");
    int num5[10] = {10,9,8,7,6,5,4,3,2,1};
    printf("1st largest in [10 9 8 7 6 5 4 3 2 1]\numsSize");
    printf("Expected: 10\numsSize");
    printf("Actual: %d\numsSize", findKthLargest(num5, 10, 1));


    return 0;
}