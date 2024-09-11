class Solution {
public:
    string DecimalToBinary(int num)
    {
        string ans="";
        for (int i = 31; i >= 0; i--) {
            int k = num >> i;
            if (k & 1)
                ans+="1";
            else
                ans+="0";
        }
        return ans;
    }
    int minBitFlips(int start, int goal) {
        string s=DecimalToBinary(start);
        string g=DecimalToBinary(goal);
        cout<<s<<" "<<g<<endl;
        int cnt=0;
        for(int i=0;i<max(s.length(),g.length());i++){
            if(i<s.length() && i<g.length() && s[i]==g[i]){
                continue;
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};