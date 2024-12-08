class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& ev) {
        sort(ev.begin(),ev.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        int m=0,ans=0;
        for(auto& e:ev){
            int str=e[0],end=e[1],v=e[2];
            while(!pq.empty()&&pq.top().first<str){
                m=max(m,pq.top().second);
                pq.pop();
            }
            ans=max(ans,m+v);
            pq.push({end,v});

        }
        return ans;
    }
};