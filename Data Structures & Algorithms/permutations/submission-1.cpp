class Solution {
   public:
    void getAllCombination(vector<int>& nums, vector<vector<int>>& ans, vector<int>& current,
                           int index, vector<bool>& visited) {
        current.push_back(nums[index]);
        visited[index] = true;
        if (current.size() == nums.size()) {
            ans.push_back(current);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                getAllCombination(nums, ans, current, i, visited);
            }
        }

        current.pop_back();
        visited[index] = false;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        vector<bool> visited(nums.size(), false);
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                getAllCombination(nums, ans, current, i, visited);
            }
        }

        return ans;
    }
};