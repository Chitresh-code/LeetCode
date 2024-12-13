class Solution {
public:
    long long findScore(vector<int>& nums) {
        // ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
        long long ans = 0;
        for(int i = 0; i < nums.size(); i += 2) {
            int i0 = i;
            while(i + 1 < nums.size() && nums[i] > nums[i + 1]) 
                ++i;
            for(int j = i; j >= i0; j -= 2) {
                ans += nums[j];
            }
        }
        return ans;
    }
};