#include<iostream>

using namespace std;

int main()
{
    int n = 5;
    int maxsum = INT8_MIN;
    int arr[5] = {1,2,3,4,5};

    for (int start = 0; start < n; start++)
    {
        for (int current = 0, end = start; end < n; end++)
        {
            current += arr[end];
            maxsum = max(maxsum,current);
        }
    }

    cout << "Maximum subarray sum = " << maxsum << endl;

    return 0;
}