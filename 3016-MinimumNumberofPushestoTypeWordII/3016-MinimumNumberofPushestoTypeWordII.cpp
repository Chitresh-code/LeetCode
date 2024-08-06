// Dhairya Kumar Singh

class Solution 
{
public:
    static bool cmp(int a, int b) 
    {
        return a > b;
    }
    int minimumPushes(string word) 
    {
        vector<int> freq(26, 0);
        for (int i = 0; i < word.length(); i++) 
        {
            freq[word[i] - 'a']++;
        }
        sort(freq.begin(), freq.end(), cmp);
        int res = 0;
        for (int i = 0; i < 26; i++) 
        {
            int position = (i / 8) + 1;
            res += position * freq[i];
        }
        return res;
    }
};