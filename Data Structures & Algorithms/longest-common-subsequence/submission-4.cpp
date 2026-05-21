class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dp(text2.size() + 1, 0);

        for (int i = 1; i <= text1.size(); i++) {
            int prev = 0;
            for (int j = 1; j <= text2.size(); j++) {
                int temp = dp[j];
                if (text1[i - 1] == text2[j - 1]) {
                    dp[j] = prev + 1;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                prev = temp;
            }
        }

        return dp[text2.size()];
    }
};
