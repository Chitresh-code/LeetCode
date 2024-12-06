class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
unordered_map<int, int>count;
// 1 to n 
for( int i= 1 ; i<=n ; i++)
{
    count [i]= 1;

}
for( int ban :banned)
{
    if(count.find(ban)!= count.end())
    {
        count.erase(ban);

    }
}
vector<int>final;

for(auto p :count)
{ 
    if(1<=  p.first<= n){
    final.push_back(p.first);}

}
if(final.empty())
{
    return 0;

}
sort(final.begin(), final.end());

int sum=0;
int cnt = 0;
for( int i = 0 ;i< final.size(); i++)
{ 
  
    if(sum+final[i]<=maxSum)
    {
         sum= sum+final[i];
         cnt++;

    }
    else{
        break;

    }
}


return cnt;
    }
};