
class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        
        // Edge case: single digit number
        if (n == "1") return "0";
        
        // Set to store all possible palindrome candidates
        set<long long> candidates;

        // Edge case candidates
        candidates.insert((long long)pow(10, len - 1) - 1); // 999...999
        candidates.insert((long long)pow(10, len) + 1);     // 1000...0001

        // Get the first half of the number
        long long firstHalf = stoll(n.substr(0, (len + 1) / 2));
        
        // Generate the palindrome candidates
        for (int i = -1; i <= 1; ++i) {
            string newHalf = to_string(firstHalf + i);
            string candidate;
            if (len % 2 == 0) {
                candidate = newHalf + string(newHalf.rbegin(), newHalf.rend());
            } else {
                candidate = newHalf + string(newHalf.rbegin() + 1, newHalf.rend());
            }
            candidates.insert(stoll(candidate));
        }
        
        // Remove the number itself if it exists in candidates
        candidates.erase(stoll(n));

        // Find the closest palindrome
        long long closest = -1;
        long long num = stoll(n);
        for (long long cand : candidates) {
            if (closest == -1 || abs(cand - num) < abs(closest - num) || 
               (abs(cand - num) == abs(closest - num) && cand < closest)) {
                closest = cand;
            }
        }

        return to_string(closest);
    }
};
