class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int t=flowerbed.size();
        int cnt=0;
        if(t==1 and n>1)
            return false;
        if(t==1 and n==1 and flowerbed[0]==1)
            return false;
        if(t==1 and n<=1 and flowerbed[0]==0)
            return true;
        
        for(int i=0;i<t;i++){
            if(i==t-1 and flowerbed[i]==0 and flowerbed[i-1]==0)
                cnt++;
            else if(i==0 and flowerbed[i]==0 and flowerbed[i+1]==0){
                cnt++;
                flowerbed[i]=1;
            }
            else{
                if(i-1>=0 and flowerbed[i-1]==0 and i+1<t and flowerbed[i+1]==0 and flowerbed[i]==0){
                    cnt++;
                    flowerbed[i]=1;
                }
            }
        }
        cout<<cnt<<endl;
        return cnt>=n;
    }
};