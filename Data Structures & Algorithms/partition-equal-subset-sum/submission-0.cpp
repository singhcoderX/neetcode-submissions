class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = getSum(nums);
        if (totalSum % 2 != 0) {
            return false;
        }
        int target = totalSum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        // dp[0][nums[0]] = true -- At index 0 we have only nums[0] -> true
        if (nums[0] <= target) {
            dp[0][nums[0]] = true;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                // not taking current element
                bool notTake = dp[i - 1][j];
                bool take = false;
                if (nums[i] <= j) {
                    take = dp[i - 1][j - nums[i]];
                }
                dp[i][j] = take || notTake;
            }
        }
        return dp[n - 1][target];   
    }
    int getSum(vector<int>& nums) {
        int ans = 0;
        for (auto& x : nums) {
            ans += x;
        }
        return ans;
    }
};
