class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxVal = 0;
        map<int, int, greater<>> dp;
        dp[0] = 1;
        for (int num : nums) {
            for (pair<int, int> p : dp) {
                dp[(num | p.first)] += dp[p.first];
            }
            maxVal |= num;
        }
        return dp[maxVal];
    }
};