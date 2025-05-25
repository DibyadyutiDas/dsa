#include<iostream>
#include<vector>
// #include <bits/stdc++.h>

using namespace std;

int main()
{
    // vector<int> vec;
    // vector<int> vec = {3,0};
    vector<int> vec= {1};

    vec.push_back(25);

    cout << vec.size() << endl;
    cout << vec.capacity();

    for (int i : vec)
    {
        cout << i << endl;
    }

    vec.pop_back();

    for (int i : vec)
    {
        cout << i << endl;
    }

    cout << vec.front() << endl;
    cout << vec.back() << endl;
    cout << vec.at(0) << endl;
    // cout << vec[0] << endl;
    
    return 0;
}