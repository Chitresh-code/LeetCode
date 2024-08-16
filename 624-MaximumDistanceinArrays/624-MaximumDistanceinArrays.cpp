class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans=INT_MIN;
        int l1=arrays[0].size()-1;
        int low=arrays[0][0];
        int high=arrays[0][l1];
        int size=arrays.size();
        for(int i=1;i<size;i++){
            int size=arrays[i].size()-1;
            ans=max({ans,abs(low-arrays[i][size]),abs(high-arrays[i][0])});
            low=min(low,arrays[i][0]);
            high=max(high,arrays[i][size]);
        }
        return ans;
    }
};