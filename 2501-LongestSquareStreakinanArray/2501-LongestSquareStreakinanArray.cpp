class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> dict(begin(nums), end(nums));

        int max_len = -1, curr_len;
        
        for(int &num: nums){
            long long new_num = num, p;

            p = sqrt(new_num);
            
            while(p*p == new_num && dict.count(p)){
                new_num = p;
                p = sqrt(new_num);
            }

            curr_len = 0;
            while(dict.count(new_num)){
                curr_len++;
                
                p = new_num;
                if(p > 100005) break;
                
                new_num = (p * p);
                
                dict.erase(p);
            }

            if(curr_len >= 2) max_len = max(max_len, curr_len);
        }

        return max_len;
    }
};