class Solution {
    private:
    void dfs(vector<vector<int>>&nums,int row,int col,int inicolor,int color,int delrow[],int delcol[]){
         nums[row][col]=color;
        int n = nums.size();
        int m = nums[0].size();
       
        for(int i = 0;i<4;i++){
            int neirow = delrow[i] + row;
            int neicol = delcol[i]+col;

            if(neirow>=0&&neirow<n&& neicol>=0&&neicol<m && nums[neirow][neicol]!=color && nums[neirow][neicol]==inicolor) {
                dfs(nums,neirow,neicol,inicolor,color,delrow,delcol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>nums= image;
        int inicolor = image[sr][sc];
        int delrow[] ={-1,0,+1,0};//these delrow and delcol used to access neighbour element
        int delcol[]={0,+1,0,-1}; 
        dfs(nums,sr,sc,inicolor,color,delrow,delcol);
        return nums;
    }
};