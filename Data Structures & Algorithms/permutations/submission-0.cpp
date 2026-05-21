class Solution {
   public:
    void getAllCombination(vector<int>& nums, vector<vector<int>>& ans, vector<int>& current,
                           int index) {

        current.push_back(nums[index]);
        if (current.size() == nums.size()) {
            ans.push_back(current);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (find(current.begin(), current.end(), nums[i]) == current.end()) {
                getAllCombination(nums, ans, current, i);
            }
        }

        current.pop_back();
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        for (int i = 0; i < nums.size(); i++) {
            getAllCombination(nums, ans, current, i);
        }

        return ans;
    }
};