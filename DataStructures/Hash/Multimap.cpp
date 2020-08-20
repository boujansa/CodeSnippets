#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

void addToKeys(multimap<int,int>& mmp, int val) {

    for (auto rit=mmp.rbegin() ; rit!=mmp.rend(); ++rit)
    {
        cout << rit->first << ":" << rit->second << endl;
        int nk = rit->first+val;
        int v = rit->second;
        auto it = mmp.find(rit->first);
        mmp.erase(it);
        mmp.insert(make_pair(nk, v));
    }

}   
int main(){
    multimap<int,int> mmp;

    mmp.insert(make_pair(1, 9));
    mmp.insert(make_pair(4, 19));
    mmp.insert(make_pair(2, 8));
    mmp.insert(make_pair(3, 34));

    for (auto it=mmp.begin() ; it!=mmp.end() ; it++)
        cout << it->first << ":" << it->second << endl;

    cout << endl;
    addToKeys(mmp, 1);
    cout << endl;

    for (auto it=mmp.begin() ; it!=mmp.end() ; it++)
        cout << it->first << ":" << it->second << endl;
    
    

}

// For your reference, see https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/