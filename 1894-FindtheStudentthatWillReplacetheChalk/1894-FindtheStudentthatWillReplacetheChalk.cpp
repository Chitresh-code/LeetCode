class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i = 0;
        long long sum = accumulate(chalk.begin(),chalk.end(),0LL);
        int rem = k % sum;
        if(rem == 0) return 0;
        while(rem > 0) {
            if(chalk[i] <= rem) {
                rem -= chalk[i];
                i++;
            }
            else break;
        }
        return i;
    }
};