class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum = 0;
        int n = skill.size();

        for (int i = 0; i < n; i++) {
            sum += skill[i];
        }

        if (sum % (n / 2) != 0) return -1;

        long long targetSum = sum / (n / 2);
        unordered_map<int, int> freq;

        for (int s : skill) {
            freq[s]++;
        }

        long long res = 0;

        for (int i : skill){
            if (freq[i] == 0) continue;
            int temp = targetSum - i;
            if (freq[temp]>0){
                freq[temp]--;
                freq[i]--;
                res+=temp*i;
            } else return -1;
        }

        return res;
    }
};
