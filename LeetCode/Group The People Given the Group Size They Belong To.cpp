class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> map;
        for(int i = 0; i < groupSizes.size(); i++){
            if(map[groupSizes[i]].size() < groupSizes[i]){
                map[groupSizes[i]].push_back(i);
            }
            if(map[groupSizes[i]].size() == groupSizes[i]){
                ans.push_back(map[groupSizes[i]]);
                map.erase(groupSizes[i]);
            }
        }
        for(auto it = map.begin(); it != map.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};
