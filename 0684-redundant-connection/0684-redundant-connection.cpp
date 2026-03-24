class Solution {
public:
    int findultpar(int u,vector<int>&parent){
        if(parent[u]==u) return u;
        return findultpar(parent[u],parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        // vector<int> parent(n,0);
        vector<int> rank(n+1,0);
        vector<int> parent(n + 1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        for(int i=0;i<n;i++){
            auto u=edges[i][0], v=edges[i][1];
            int pu=findultpar(u, parent);
            int pv=findultpar(v,parent);
            if(pu==pv) return edges[i];
            if(rank[pu]>rank[pv]){
                parent[pv]=pu;
            }
            else if(rank[pv]>rank[pu]){
                parent[pu]=pv;
            }
            else {
                parent[pv]=pu;
                rank[pu]++;
            }
        }
        return {};

        
    }
};