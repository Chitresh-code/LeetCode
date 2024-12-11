class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = 0;
        int cnt = 0;
        int ans = 0;
        while(j<n){
            if(nums[j]-nums[i]<=2*k){
                j++;
                cnt++;
                ans = max(cnt,ans);
            }
            else{
                while(i<=j && nums[j]-nums[i]>2*k){
                    i++;
                    cnt--;
                }
            }
        }
        return ans;
    }
};