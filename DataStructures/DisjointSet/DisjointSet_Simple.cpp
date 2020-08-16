class DisjointSet {
private:
    int* parent;
        
public:
    int count;
    DisjointSet(int num)
    {
        // this can be modified such that we only increament count under certain conditions
        parent= new int[nums];
        for(int i=0 ; i<nums ; i++)
        {
            count++;
            parent[i] = i;
        }
    }
    
    void Union(int a, int b)
    {
        int pa = Find(a);
        int pb = Find(b);
        
        if (pa != pb)
        {
            // Send the parent of a to be the parent of b
            // we can also do the other way around as well, as long as we are only operating on the parents
            parent[pb] = pa;

            // Since we joined two distinct sets, we reduce the total count
            count--;
        }
    }
    
    int Find(int a)
    {
        if (a == parent[a])
            return a;
        
        return Find(parent[a]);
    }
};