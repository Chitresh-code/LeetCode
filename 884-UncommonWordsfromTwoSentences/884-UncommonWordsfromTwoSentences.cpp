class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;
        map<string,int>mp1, mp2;
        string tmp="";
        for(int i=0;i<s1.size();i++){
            if(s1[i]==' '){
                mp1[tmp]++;
                tmp="";
            }else  tmp += s1[i];
        }
        mp1[tmp]++;
        string tmp2 ="";
            for(int i=0;i<s2.size();i++){
            if(s2[i]==' '){
                mp2[tmp2]++;
                tmp2="";
            }else  tmp2 += s2[i];
        }
        mp2[tmp2]++;
        for(auto it:mp1){
            if(it.second == 1 && ! mp2[it.first]){
                ans.push_back(it.first);
            }
        }
        for(auto it:mp2){
            if(it.second == 1 && ! mp1[it.first]){
                ans.push_back(it.first);
            }
        }
    return ans;
    }
};