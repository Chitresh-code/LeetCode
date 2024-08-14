class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        while (a || b || c){
             int a1=(1&a);
              a=a>>1;
             int b1=(1&b);
              b=b>>1;
             int c1=(1&c);
             c=c>>1;

             if(a1 && b1 && !c1){
               count+=2;
               continue;
             }

             if(c1){
               count+=(1-(a1|b1));
            }
            else{
               count+=(a1|b1);
            }



        }

        return count;
    }
};