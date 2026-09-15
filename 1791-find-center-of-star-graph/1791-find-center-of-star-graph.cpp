class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //any two nodes
        vector<int> first = edges[0];
        vector<int> second = edges[1];
        //check which element present in both node i.e common on both edges
        if(first[0]==second[0]||first[0]==second[1]){
            return first[0];
        }
        return first[1];

    }
};