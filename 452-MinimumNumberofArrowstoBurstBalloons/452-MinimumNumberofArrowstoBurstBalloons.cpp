class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int,int>>nums;
        for(const auto& point : points) {
            nums.emplace_back(point[0],point[1]);
        }
        int count=0;
        sort(nums.begin(),nums.end());
        pair<int,int>current=nums[0];
        for(int i=0;i<nums.size();i++){
                if(current.second>=nums[i].first){
                    count++;
                    current.second = min(current.second, nums[i].second);
            } else {
                current = nums[i];
            }
        }int sum=nums.size()-count;
            return sum+1;
        
    
}};