class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=s.size();
        vector<vector<int>> dp(n);
        int pos=0,sz;
        for(int i=0;i<dictionary.size();i++){
            pos=0;
            sz=dictionary[i].size();
            while(true){
                pos=s.find(dictionary[i], pos);
                if(pos!=string::npos){
                    dp[pos+sz-1].push_back(sz);
                    pos++;
                }
                else{
                    break;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(dp[i].size()==0){
                dp[i].push_back(0);
            }
            if(dp[i][0]<=i)
            dp[i][0]+=dp[i-dp[i][0]][0];
            if(i>0)
            dp[i][0]=max(dp[i][0],dp[i-1][0]);
            for(int j=1;j<dp[i].size();j++){
                if(i>=dp[i][j])
                dp[i][0]=max(dp[i][0],dp[i][j]+dp[i-dp[i][j]][0]);
                else
                dp[i][0]=max(dp[i][0],dp[i][j]);
            }
        }

        return s.size()-dp[n-1][0];

    }
};