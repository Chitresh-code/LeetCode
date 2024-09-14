class Solution {
public:
    
    int longestSubarray(vector<int>& nums) {
        int large = 0,ans = 0,pairs = 0;
        for(auto num : nums){
            if(large < num){
                large = num;
                ans = 0;
                pairs = 0;
            }
            if (large == num){
                pairs++;
            }
            else{
                pairs=0;
            }
            ans = max(ans,pairs);
        }
        return ans;
    }
};