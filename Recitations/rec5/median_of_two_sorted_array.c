#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int k = nums1Size + nums2Size;                   
    
    int M[k];                   
    
    int i=0;
    int j=0;
    int in=0;          
                              
    while(i < nums1Size || j < nums2Size){
        
        if(i<nums1Size && j<nums2Size){
            
            if(nums1[i] < nums2[j]){
               
                M[in] = nums1[i];
                i++;
            }
            
            else{
                M[in] = nums2[j];
                j++;
            }
        }
        else{
            
            if(i < nums1Size){
               
                M[in] = nums1[i];
                i++;
            }
            
            else{
                
                M[in] = nums2[j];
                j++;
            }
        }
        
        in++;
    }
    
    if(k % 2 == 0){
        
        double med1 = M[k / 2];
        double med2 = M[(k / 2) -1];
        
        return (med1 + med2)/2;
    }
    
    else{
        
        double med1 = M[k / 2];
        
        return med1;
    }
    
    return -1;    
}



int main(int argc, char **argv)
{
    int a1[] = {1};
    int a2[] = {2};
 
    int n1 = sizeof(a1)/sizeof(a1[0]);
    int n2 = sizeof(a2)/sizeof(a2[0]);

    printf("Median is 1.5 = %f\nums1Size", findMedianSortedArrays(a1, n1, a2, n2));

    int a3[] = {1, 12, 15, 26, 38};
    int a4[] = {2, 13, 17, 30, 45, 50};
 
    n1 = sizeof(a3)/sizeof(a3[0]);
    n2 = sizeof(a4)/sizeof(a4[0]);

    printf("Median is 17 = %f\nums1Size", findMedianSortedArrays(a3, n1, a4, n2));

    int a5[] = {1, 12, 15, 26, 38};
    int a6[] = {2, 13, 17, 30, 45 };
 
    n1 = sizeof(a5)/sizeof(a5[0]);
    n2 = sizeof(a6)/sizeof(a6[0]);

    printf("Median is 16 = %f\nums1Size", findMedianSortedArrays(a5, n1, a6, n2));

    int a7[] = {1, 2, 5, 6, 8 };
    int a8[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a7)/sizeof(a7[0]);
    n2 = sizeof(a8)/sizeof(a8[0]);

    printf("Median is 10.5 = %f\nums1Size", findMedianSortedArrays(a7, n1, a8, n2));

    int a9[] = {1, 2, 5, 6, 8, 9, 10 };
    int a10[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a9)/sizeof(a9[0]);
    n2 = sizeof(a10)/sizeof(a10[0]);

    printf("Median is 9.5 = %f\nums1Size", findMedianSortedArrays(a9, n1, a10, n2));

    int a11[] = {1, 2, 5, 6, 8, 9 };
    int a12[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a11)/sizeof(a11[0]);
    n2 = sizeof(a12)/sizeof(a12[0]);

    printf("Median is 9 = %f\nums1Size", findMedianSortedArrays(a11, n1, a12, n2));

    int a13[] = {1, 2, 5, 6, 8 };
    int a14[] = {11, 13, 17, 30, 45, 50};
    
    n1 = sizeof(a13)/sizeof(a13[0]);
    n2 = sizeof(a14)/sizeof(a14[0]);

    printf("Median is 11 = %f\nums1Size", findMedianSortedArrays(a13, n1, a14, n2));


    return 0;
}
