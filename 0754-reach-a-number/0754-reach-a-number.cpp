class Solution {
public:
    int reachNumber(int target) {
         target = abs(target);
        int sum = 0,step = 0;
        while(target>sum){
            sum+=step;
            step++;
        }
        while((sum-target)%2==1){
            sum+=step;
            step++;
        }
        return step-1;
    }
};