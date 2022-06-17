class Solution {
public:
    int largestVariance(string s) {
        int res=0;
        for(char i='a';i<='z';i++){
            for(char j='a';j<='z';j++){
                int cnt1=0,cnt2=0;
                bool flag=false;
                for(auto &str:s){
                    if(i==j)
                        continue;
                    if(str==i)
                        cnt1++;
                    if(str==j)
                        cnt2++;
                    
                    if(cnt2>0){
                        res=max(res,cnt1-cnt2);
                    }
                    else if(cnt2==0 and flag){
                        res=max(res,cnt1-cnt2-1);
                    }
                    
                    if(cnt2>cnt1){
                        cnt1=cnt2=0;
                        flag=true;
                    }
                }
            }
        }
        return res;
    }
};