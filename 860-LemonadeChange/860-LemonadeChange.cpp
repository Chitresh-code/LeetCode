class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int fives_count=0,tens_count=0,tws_count=0;
        for(int i:bills){
            if(i==5) fives_count++;
            else if(i==10){
                fives_count--;
                if(fives_count<0) return false;
                tens_count++;
            }
            else{
                if(tens_count>=1 && fives_count>=1){
                    tens_count--;
                    fives_count--;
                    tws_count++;
                }
                else if(fives_count>=3) fives_count=fives_count-3;
                else return false;
            }
        }
        return true;
    }
};