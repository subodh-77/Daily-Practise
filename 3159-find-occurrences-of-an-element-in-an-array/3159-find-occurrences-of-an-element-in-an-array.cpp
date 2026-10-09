class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries,int x) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        vector<int> result;
        for (int i = 0; i < queries.size(); i++) {
            if (queries[i] <= mp[x].size()) {
                result.push_back(mp[x][queries[i] - 1]);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }
};