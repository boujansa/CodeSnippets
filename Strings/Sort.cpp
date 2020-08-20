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

void print(vector<int>& vec) {

    for (auto& v : vec)
        cout << v << " ";
    cout << endl;
}

int getMin(vector<int>& a) {
    return *min_element(a.begin(), a.end());
}


static bool sortVec(vector<int>& a, vector<int>& b) {
    return getMin(a) < getMin(b);
}

int main()
{
    // sorting a string
    string s1 = "dbafdl";
    sort(s1.begin(), s1.end());
    
    // Sorting an array of strings
    vector<string> vec = {"obc", "xyz", "cfg", "abc"};
    sort(vec.begin(), vec.end());

    // Sorting an array of arrays
    vector<int> v1 = {56,5,16};
    vector<int> v3 = {9,10,23};
    vector<int> v2 = {220,4,7};
    vector<vector<int>> vvec;
    vvec.push_back(v1);
    vvec.push_back(v2);
    vvec.push_back(v3);

    // sort(vvec.begin(), vvec.end(), sortVec);
    sort(vvec.begin(), vvec.end(), [](vector<int>& a, vector<int>& b){ return getMin(a) < getMin(b); });
    for (auto& v : vvec)
        print(v);
    
    return 0;
}


