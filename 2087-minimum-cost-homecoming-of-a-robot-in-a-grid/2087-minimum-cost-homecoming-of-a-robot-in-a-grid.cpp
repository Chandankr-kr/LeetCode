class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        
        int res=0;
        int a=startPos[0],b=startPos[1];
    
            if(a<homePos[0]){
                for(int i=a+1;i<=homePos[0];i++){
                    res+=rowCosts[i];
                }
            }
            else{
                for(int i=a-1;i>=homePos[0];i--){
                    res+=rowCosts[i];
                }
            }
        
        if(b<homePos[1]){
                for(int i=b+1;i<=homePos[1];i++){
                    res+=colCosts[i];
                }
            }
            else{
                for(int i=b-1;i>=homePos[1];i--){
                    res+=colCosts[i];
                }
            }
        return res;
    }
};