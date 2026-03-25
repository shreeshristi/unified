class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& edges) {
        int v = numCourses;
        vector<int> indegree(v, 0);
        vector<vector<int>> adj(v);

        for(auto &edge : edges) {          //adj and indegree
            int u = edge[0], w = edge[1];
            adj[w].push_back(u); // w -> u
            indegree[u]++;
        }
        queue<int> q;                        //queue
        for(int i = 0; i < v; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        int cnt = 0;                     //queue empty
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        return cnt == v;               //total nodes popped is total nodes then all read
    }
};