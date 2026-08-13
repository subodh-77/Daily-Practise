class Solution {
public:
    std::vector<std::vector<int>> groupThePeople(std::vector<int>& groupSizes) {
        std::unordered_map<int, std::vector<int>> group_map;
        std::vector<std::vector<int>> result;
        
        for (int i = 0; i < groupSizes.size(); ++i) {
            int size = groupSizes[i];
            group_map[size].push_back(i);
            
            // If the group reaches its required size, add it to the result and reset
            if (group_map[size].size() == size) {
                result.push_back(group_map[size]);
                group_map[size].clear();
            }
        }
        
        return result;
    }
};