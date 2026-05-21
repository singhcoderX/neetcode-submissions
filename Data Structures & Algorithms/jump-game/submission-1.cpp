class Solution {
   public:
    bool canJump(vector<int>& arr) {
        int maxReachSoFar = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (i > maxReachSoFar) {
                return false;
            }
            if (maxReachSoFar < arr[i] + i) {
                maxReachSoFar = arr[i] + i;
            }
        }

        if (maxReachSoFar >= arr.size() - 1) {
            return true;
        } else {
            return false;
        }
    }
};
