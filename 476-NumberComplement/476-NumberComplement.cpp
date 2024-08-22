class Solution
{
    public:

        string findBit(int num)
        {
            string binary = "";
            while (num > 0)
            {
                binary = to_string(num % 2) + binary;
                num /= 2;
            }
            return binary;
        }

        string findXor(string& binary){
            string res = "";

            for(auto bit : binary){
                res += (bit) == '1' ? '0' : '1';
            }
            return res;
        }
    int findComplement(int num) {
        string binary = findBit(num);
        string complement = findXor(binary);
        reverse(complement.begin(),complement.end());
        int n = complement.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(complement[i] == '1'){
                ans += pow(2,i);
            }
        }
        return ans;
    }
};

