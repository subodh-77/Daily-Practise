class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int prev = skills[0];int consecutive_win = 0;int winnerId = 0;
        int n = skills.size();
        for(int i = 1;i<n;i++){
            if(prev<skills[i]){
                consecutive_win=0;
                prev = skills[i];
                winnerId=i;
            }
            consecutive_win++;
            if(consecutive_win>=k)break;
        }
        return winnerId;

    }
};