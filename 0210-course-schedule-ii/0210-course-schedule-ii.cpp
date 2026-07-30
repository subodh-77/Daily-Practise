class Solution {
public:
//using kahn's algo for topo sort
vector<int>topsort(unordered_map<int,vector<int>>&adj,vector<int>&indegree,int n){
        queue<int>que;
        //where indegree[i]==0 push in que
        for(int i = 0;i<n;i++){
            if(indegree[i]==0){
                que.push(i);
            }
        }
        vector<int>result;
        //bfs
        while(!que.empty()){
            int u = que.front();
            result.push_back(u);
            que.pop();
            for(int v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    que.push(v);
                }
            }
        }if(result.size() != n)
    return {};
        return result;

}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        for(int i = 0;i<prerequisites.size();i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);//b-->a kyunki b se a mein jaunga agr a lena ha toh
            indegree[a]++;
        }
        return topsort(adj,indegree,numCourses);
        
    }
};