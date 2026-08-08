class Solution {
public:
int dfs(int u,vector<int>&color,vector<vector<int>>& graph,int curr_color){
    color[u]=curr_color;
    for(int v:graph[u]){
         if(color[v]==color[u]){return false;}
        if(color[v]==-1){
            int colorOfV=1-curr_color;//changes to different color
            if(!dfs(v,color,graph,colorOfV))return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i = 0;i<n;i++){
            if(color[i]==-1){
                 if(!dfs(i,color,graph,0))return false;
            }
        }
        return true;
    }
};