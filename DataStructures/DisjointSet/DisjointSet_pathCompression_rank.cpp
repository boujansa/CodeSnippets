class DisjointSet {
private:
    int* parent;
    int* rank;
public:
    int count;
    DisjointSet(int num)
    {
        // this can be modified such that we only increament count under certain conditions
        parent = new int[num];
        rank = new int[num];
        count = 0;
        for(int i=0 ; i<nums ; i++)
        {
            count++;
            parent[i] = i;
        }
    }
    
    ~DisjointSet()
    {
        delete [] parent;
        delete [] rank;
    }

    void Union(int a, int b)
    {
        int pa = Find(a);
        int pb = Find(b);
        
        // if the parents are not the same, it means they belong to two distinct sets
        if (pa != pb)
        {
            // put the lower rank tree under the higher rank tree
            if (rank[pa] > rank[pb])
                parent[pb] = pa;
            else if (rank[pb] > rank[pa])
                parent[pa] = pb;
            else
            {
                parent[pa] = pb;
                rank[pb]++;
            }
            count--;
        }
    }
    
    int Find(int a)
    {
        if (parent[a] != a)
        {
            // this is path compression
            // meaning we make the node point directly to its parent, instead of having multiple levels
            parent[a] = Find(parent[a]);
        }
        
        // parent and node are same, so we return
        return parent[a];
    }
};