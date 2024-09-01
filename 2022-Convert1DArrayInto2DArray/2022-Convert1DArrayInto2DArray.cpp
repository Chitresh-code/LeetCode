class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        vector<vector<int>> ans(m,vector<int>(n));
        int i=0;
        if(m*n!=original.size()) return {};
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                ans[j][k]=original[i];
                i++;
            }
        }
        return ans;
    }
};