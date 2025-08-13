class Solution {
public:
    int N;
    class UnionFind {
        public:
            vector<int> parent;
            vector<int> rank;
            
            UnionFind(int n) {
                parent.resize(n);
                rank.resize(n, 0);
                for (int i = 0; i < n; i++) {
                    parent[i] = i;
                }
            }

            int find (int x) {
                if (x == parent[x]) 
                    return x;
            
                return parent[x] = find(parent[x]);
            }
            
            void Union (int x, int y) {
                int x_parent = find(x);
                int y_parent = find(y);
            
                if (x_parent == y_parent) 
                    return;
            
                if(rank[x_parent] > rank[y_parent]) {
                    parent[y_parent] = x_parent;
                } else if(rank[x_parent] < rank[y_parent]) {
                    parent[x_parent] = y_parent;
                } else {
                    parent[x_parent] = y_parent;
                    rank[y_parent]++;
                }
            }
    };


    int kruskal(vector<vector<int>> &vec, int skip, int add) {

        int sum = 0;
        UnionFind uf(N);
        if (add != -1) {
            uf.Union(vec[add][0], vec[add][1]);
            sum += vec[add][2]; 
        }
        for(int i = 0; i<vec.size(); i++) {
            
            if (i == skip) continue; 

            int u = vec[i][0];
            int v = vec[i][1];
            int wt = vec[i][2];
            
            int parent_u = uf.find(u);
            int parent_v = uf.find(v);
            
            if(parent_u != parent_v) {
                uf.Union(u, v);
                sum += wt;
            }
           
        }  

        for(int i = 0; i < N; i++) {
            if(uf.find(i) != uf.find(0))
                return INT_MAX;
        }        
        
        return sum;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N = n;
        for(int i = 0; i<edges.size(); i++) {
            edges[i].push_back(i);
        }
        auto lambda = [&] (vector<int>& v1, vector<int>& v2) {
            return v1[2] < v2[2];
        };
        sort(edges.begin(), edges.end(), lambda);
        int mst = kruskal(edges, -1, -1);
        vector<int> c;
        vector<int> pc;

        for (int i = 0; i<edges.size(); i++) {
            if (kruskal(edges, i, -1) > mst) {
                c.push_back(edges[i][3]);
            }
            else if(kruskal(edges, -1, i) == mst) {
                pc.push_back(edges[i][3]);
            }
        }

        return {c,pc};
    }
};