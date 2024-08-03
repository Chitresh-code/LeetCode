class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_multiset<int> s(target.cbegin(), target.cend());

        for (const int& el: arr)
            if (auto it = s.find(el); it != s.end())
                s.erase(it);
            else
                return false;

        return true;
    }
};