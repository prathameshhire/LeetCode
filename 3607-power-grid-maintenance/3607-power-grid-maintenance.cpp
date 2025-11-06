class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {


        map<int , set<int>>ComponentIdToElement;

        // bfs

        vector<vector<int>>adj(c + 1);

        for(auto node : connections){

            int u = node[0];
            int v = node[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>vis(c+1, 0);
        
        vector<int>component(c +1);

        int id = 0;

        for(int i =1; i<= c; i++){

            if(!vis[i]){
                
                id++;
                dfs(i,  id, vis,adj,component, ComponentIdToElement);
            }
        }

        vector<int>ans;

        for(auto q : queries){

            if(q[0]==1){
                 
                 if(ComponentIdToElement[component[q[1]]].find(q[1]) !=ComponentIdToElement[component[q[1]]].end()){

                    ans.push_back(q[1]);
                 }else{

                    ans.push_back(*ComponentIdToElement[component[q[1]]].begin());
                 }

            }else{

                 ComponentIdToElement[component[q[1]]].erase(q[1]);
            }
        }

        for(int i =0; i< ans.size();i++){

            if(ans[i]==0)ans[i] = -1;
        }

        return ans;
        
    }

    private:

    void dfs(int start, int id , vector<int>& vis, vector<vector<int>>& adj,vector<int>&component, map<int, set<int>>& ComponentIdToElement){

            vis[start] = 1;
            component[start] = id;
            ComponentIdToElement[id].insert(start);

            for(auto nd : adj[start]){

                if(!vis[nd]){
                    dfs(nd, id, vis, adj, component,ComponentIdToElement );
                }
            }

    }


};