class Solution {
public:
    void backtrack(int& ans, int n, vector<int>& nums, vector<int>& temp, vector<int>& visited){
        if(temp.size() == n){
            ans++;
            return;
        }

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                int pos = temp.size() + 1;
                if(nums[i]%(pos) == 0 || (pos)%nums[i] == 0){
                    temp.push_back(nums[i]);
                    visited[i] = 1;
                    backtrack(ans, n, nums, temp, visited);
                    temp.pop_back();
                    visited[i] = 0;
                }
            }
        }
        
    }

    int countArrangement(int n) {
        int ans = 0;    
        vector<int> nums;
        vector<int> temp;
        vector<int> visited(n, 0);
        for(int i = 0; i < n; i++){
            nums.push_back(i+1);
        }

        backtrack(ans, n, nums, temp, visited);
        return ans;
    }
};
