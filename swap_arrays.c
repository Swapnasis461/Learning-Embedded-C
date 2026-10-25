/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdint.h>

void display_arr (uint8_t *parr, uint32_t n);    //function prototype
void swap_arr (uint8_t *parr1, uint8_t *parr2, uint32_t n1, uint32_t n2);  //function prototype

int main()
{
    uint32_t n1,n2;
    printf("Enter the size of the array1: ");
    scanf("%d",&n1);
    printf("\nEnter the size of the array2: ");
    scanf("%d",&n2);
    
    uint8_t arr1[n1], arr2[n2];
    
    printf("\nEnter the elements of the array1: \n");
    for (uint32_t i = 0; i < n1; i++)
    {
        printf("Enter %d element of array1:",i);
        scanf("%d",&arr1[i]);
    }

    printf("Enter the elements of the array2: \n");
    for (uint32_t i = 0; i < n2; i++)
    {
        printf("Enter %d element of array1:",i);
        scanf("%d",&arr2[i]);
    }
    
    printf("contents of the array before swap:\n");
    
    display_arr(arr1,n1);
    printf("\n");
    display_arr(arr2,n2);
    printf("\n");
    
    printf("contents of the arrays after swap:\n");
    swap_arr(arr1, arr2, n1, n2);
    return 0;
}

void display_arr (uint8_t *parr, uint32_t n)
{
    for(uint32_t i = 0; i < n; i++)
    {
        printf("%d ", parr[i]);
    }
}

void swap_arr (uint8_t *parr1, uint8_t *parr2, uint32_t n1, uint32_t n2)
{
    uint32_t n = n1<n2? n1 : n2;
    uint8_t temp = 0;
    
    for(uint32_t i = 0; i<n; i++)
    {
        temp = parr1[i];
        parr1[i] = parr2[i];
        parr2[i] = temp;
    }
    
    display_arr(parr1,n1);
    printf("\n");
    display_arr(parr2,n2);
    printf("\n");
}
