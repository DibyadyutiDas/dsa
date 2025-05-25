#include<iostream>
using namespace std;

void solve(string name, int index);

int main()
{
    string name = "bro";
    solve(name, 0);
    return 0;
}

void solve(string name, int index) {
    if (index == name.size()) {
        cout << name << endl;
        return;
    }
    for (int i = index; i < name.size(); i++) {
        swap(name[i], name[index]);
        solve(name, index + 1);
        swap(name[i], name[index]); // backtrack
    }
}