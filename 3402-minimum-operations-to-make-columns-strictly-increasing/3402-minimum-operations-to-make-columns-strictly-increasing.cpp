class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int count = 0;
        int r = grid.size();
        int c = grid[0].size();
        for(int j = 0;j<c;j++){
            for(int i = 1;i<r;i++){
               if( grid[i][j]<=grid[i-1][j]){
                 count+= grid[i-1][j]-grid[i][j]+1;
                grid[i][j]=grid[i-1][j]+1;
               }
               
            }
        }
         for(int i = 0;i<r;i++){
         for(int j = 0;j<c;j++){
         cout<<grid[i][j];}cout<<endl;}
           
            
        return count;
    }
};