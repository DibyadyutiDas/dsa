// C program to read string from user
#include<stdio.h>
   
int main()
{   
    // declaring string
    char str[50];
       
    // reading string
    scanf("%s",str);
       
    // print string
    printf("%s",str);
   
    return 0;
}

// Input
// GeeksforGeeks
// Output
// GeeksforGeeks

// Input
// Geeks for Geeks
// Output
// Geeks

// // C Program to take string separated by whitespace using scanset characters
// #include <stdio.h>

// int main()
// {
 
//     char str[20];
 
//     // using scanset in scanf
//     scanf("%[^\n]s", str);
 
//     // printing read string
//     printf("%s", str);
 
//     return 0;
// }

// Input

// Geeks for Geeks
// Output

// Geeks for Geeks