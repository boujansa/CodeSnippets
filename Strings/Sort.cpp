#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

// Compile me: g++ Sort.cpp -o Sort
// Run me: ./Sort

using namespace std;

static bool sortStr(char a, char b)
{
    return a < b;
}

int main()
{
    string s1 = "dbafdl";
    cout << s1 << endl;
    sort(s1.begin(), s1.end(), sortStr);
    cout << s1 << endl;
    
    return 0;
}


