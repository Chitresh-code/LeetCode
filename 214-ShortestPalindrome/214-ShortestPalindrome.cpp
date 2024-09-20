class Solution {
public:
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        string str=s+'#'+rev;
        int N=str.size();
        int len=0;
        int i=1;
        vector<int>LPS(N);
        while(i<N)
        {
           
           if(str[i]==str[len])
           {
            len++;
            LPS[i]=len;
            i++;
           }
           else
           {
            if(len>0)
              len=LPS[len-1];
              else
              {
                LPS[i]=0;
                i++;
              }
           }
        }
        string res=rev.substr(0,s.size()-LPS[N-1])+s;
        return res;
        
    }
};