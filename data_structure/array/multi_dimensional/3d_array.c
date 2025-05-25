// C Program to illustrate the 3d array
#include <stdio.h>
 
int main()
{
 
    // 3D array declaration
    int arr[2][2][2] = { 10, 20, 30, 40, 50, 60 };
 
    // printing elements
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            for (int k = 0; k < 2; k++) 
            {
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n \n");
    }
    
    return 0;
}