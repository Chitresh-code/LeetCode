class Solution {
public:
    int minLength(string s) {
        stack<int>st;
         
         for(int i=0;i<s.size();i++){
             if(s[i]=='B'){
                
                if(not st.empty() && st.top()=='A'){        
                    st.pop();
                    
                }
                else{
                    st.push(s[i]);

                }
             }

             else if(s[i]=='D' ){
                    
                    if(not st.empty() && st.top()=='C') st.pop();

                    else{
                        st.push(s[i]);
                    }
             }

             else{
                st.push(s[i]);
             }
         }

         return st.size();
    }
};