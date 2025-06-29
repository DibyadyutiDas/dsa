#include<iostream>

using namespace std;

int main()
{
    int n = 5;
    int current = 0;
    int maxsum = INT8_MIN;
    int arr[5] = {1,2,3,4,5};

    for (int i = 0; i < n; i++)
    {
        current += arr[i];
        maxsum = max(maxsum,current);

        if (current < 0)
        {
            current = 0;
        }
    }

    cout << "Maximum subarray sum = " << maxsum << endl;

    return 0;
}