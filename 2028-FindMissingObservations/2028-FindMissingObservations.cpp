class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int mSum=accumulate(rolls.begin(),rolls.end(),0);
        int nSum=mean*(n+m)-mSum;

        if(nSum<n || nSum>6*n){
            return{};
        }
        vector<int> v(n,1);
        int currSum=n;
        int i;
        for(i=0;i<n && currSum+5<=nSum;i++){
            v[i]=6;
            currSum+=5;
        }
        if(currSum<nSum){
            v[i]=nSum-currSum+1;
        }
        return v;
    }
};