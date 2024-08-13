class Solution {
public:
     void solve(vector<int>& candidates,int n, int target,vector<vector<int>>&ans,vector<int>&taken){

            if(target==0){
            ans.push_back(taken);
            return;
          }     
       
        for(int i=n;i<candidates.size();i++){
            if(i>n&& candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target)break;
            taken.push_back(candidates[i]);
            solve(candidates,i+1,target-candidates[i],ans,taken);
            taken.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>taken;
        vector<vector<int>>ans;
        solve(candidates,0,target,ans,taken);
      return ans;
    }
};