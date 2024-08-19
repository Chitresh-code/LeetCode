class Solution {
public:
    int minSteps(int n) {
        
        int copy = 1;
        if(n == 1){
            return 0;
        }
        int t = n-1;
        int cnt = 0;
        while(t > 0){
            if(t/(n-t) > 0 && t%(n-t) == 0){
                cnt++;
                copy = n-t;
                t -= copy;
               
            }else{
                t -= copy;
                
            }
            cnt++;
        }
        return cnt;

    }
};