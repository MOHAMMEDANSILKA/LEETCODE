class Solution {
public:
    vector<vector<int>> solve(vector<int>& nums, vector<vector<int>>& ans, int index) {
        if (index >= nums.size()) {
            ans.push_back(nums); // Store the current permutation
            return ans;
        }
        for (int j = index; j < nums.size(); j++) {
            swap(nums[index], nums[j]); // Swap to form a new permutation
            solve(nums, ans, index + 1); // Recursive call for the next index
            swap(nums[index], nums[j]); // Backtrack to restore original state
        }
        return ans;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, ans, 0);
        return ans;
    }
};
