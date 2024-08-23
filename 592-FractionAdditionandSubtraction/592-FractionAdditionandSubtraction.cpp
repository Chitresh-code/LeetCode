class Solution {
public:
    string fractionAddition(string expression) {
        int num = 0, denom = 1, n = 0, d = 0, sign = 1;
        istringstream ss(expression);
        char slash, plus_minus;
        while (ss >> n >> slash >> d) {
            num = num * d + sign * n * denom;
            denom *= d;
            int g = gcd(abs(num), denom);
            num /= g;
            denom /= g;
            ss >> plus_minus;
            sign = (plus_minus == '-') ? -1 : 1;
        }
        return to_string(num) + "/" + to_string(denom);
    }
    
private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
