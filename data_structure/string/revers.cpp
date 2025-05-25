// A Simple Iterative C++ program to reverse a string
#include <bits/stdc++.h>
using namespace std;
 
// Function to reverse a string
void reverseStr(string& str)
{
    int n = str.length();
 
    // Swap character starting from two
    // corners
    // i is the left pointer and j is the right pointer
    for (int i = 0, j = n - 1; i < j; i++, j--)
        swap(str[i], str[j]);
}
 
// Driver program
int main()
{
    string str = "geeksforgeeks";
    reverseStr(str);
    cout << str;
    return 0;
}

// // Recursive C++ program to reverse a string
//#include <bits/stdc++.h>

// using namespace std;
 
// // Recursive function to reverse the string
// void recursiveReverse(string &str, int i = 0)
// {
//     int n = str.length();
//     if (i == n / 2)
//         return;
//   // Swap the i and n-i-1 character
//     swap(str[i], str[n - i - 1]);
//   // Call Recursive function after incrementing i.
//     recursiveReverse(str, i + 1);
// }
 
// // Driver program
// int main()
// {
//     string str = "geeksforgeeks";
//     recursiveReverse(str);
//     cout << str;

//     return 0;
// }


//#include <bits/stdc++.h>

// void reverseStringLoop(char inputStr[]) {
// 	int length = strlen(inputStr);
// 	for (int i = length - 1; i >= 0; i--) {
// 		printf("%c", inputStr[i]);
// 	}
// 	printf("\n");
// }

// int main() {
// 	char originalStr[] = "GeeksforGeeks";
// 	reverseStringLoop(originalStr);
	
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;
 
// int main()
// {
//     string str = "geeksforgeeks"; // Input string
//     reverse(str.begin(),str.end()); // Reverse the string
//     cout << str << std::endl;

//     return 0;
// }