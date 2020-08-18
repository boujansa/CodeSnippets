#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

// Compile me: g++ Sort.cpp -o Sort
// Run me: ./Sort

using namespace std;

static bool sortStr(char a, char b)
{
    return a < b;
}

int main()
{
    string str = "2134";
    stringstream ss (str);

    int x;
    ss >> x;

    int y;
    istringstream(str) >> y;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    
    return 0;
}


