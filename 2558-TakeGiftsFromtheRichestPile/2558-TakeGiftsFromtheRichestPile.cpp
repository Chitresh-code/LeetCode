class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for(auto x: gifts)  pq.push(x);

        while(k--){
            auto curr = pq.top();
            pq.pop();

            int temp = sqrt(curr);
            pq.push(temp);
        }

        long long res = 0;

        while(!pq.empty()){
            res += pq.top();
            pq.pop();
        }

        return res;
    }
};