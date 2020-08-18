#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void ap_util(unordered_map<int, vector<int>>& g, vector<bool>& visited, vector<int>& parent, vector<int>& disc, vector<int>& low, vector<bool>& ap, int u, int& time) {
    visited[u] = true;

    // new node, we set the discovery and low to time++
    disc[u] = low[u] = ++time;

    // visit all adj nodes
    for (auto& v : g[u])
    {
        // only visit the ones we have not visited yet
        if (!visited[v])
        {
            parent[v] = u;
            ap_util(g, visited, parent, disc, low, ap, v, time);

            low[u] = min(low[u], low[v]);

            // u is not a root, and its disc <= child's low time: meaning there is no back edge to one of u's ancestors
            else if (disc[u] < low[v])
                ap[u] = true;
        }
        // if this is not the parent of the current node, then we check if v has a discovery time smaller than u's low time. if we so, we use that
        // this means there is another wayt to reach u from v that is cheaper
        else if (parent[u] != v)
            low[u] = min(low[u], disc[v]);
    }
}

void AP(unordered_map<int, vector<int>>& g, vector<bool>& visited, vector<int>& parent, vector<int>& disc, vector<int>& low, vector<bool>& ap) {
    
    int time = 0;

    for (int i=0 ; i<visited.size() ; i++)
        if (!visited[i])
            ap_util(g, visited, parent, disc, low, ap, i, time);

    for (int i=0 ; i<ap.size() ; i++)
        if (ap[i])
            cout << i << endl; 
}

int main(){
    cout << "hello" << endl;
    unordered_map<int, vector<int>> g;
    int n = 5;
    g[0].push_back(2);
    g[0].push_back(1);

    g[1].push_back(2);
    g[1].push_back(0);
    g[1].push_back(3);

    g[2].push_back(0);
    g[2].push_back(1);

    g[3].push_back(1);

    vector<bool> visited = vector<bool>(n, false);
    vector<int> parent = vector<int>(n, -1);
    vector<int> disc = vector<int>(n, 0);
    vector<int> low = vector<int>(n, 0);
    vector<bool> ap = vector<bool>(n, false);

    AP(g, visited, parent, disc, low, ap);
}

// For your reference, see https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/