class Solution {
public:
   vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
       vector<int> answer(nums.size());
       int mask = (1 << maximumBit) - 1, xr = 0;
       for (int i = 0; i < nums.size(); ++i) {
           xr ^= nums[i];
           answer[nums.size() - 1 - i] = (~xr) & mask;
       }
       return answer;
   }
};