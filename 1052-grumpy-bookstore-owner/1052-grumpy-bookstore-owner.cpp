class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0,n=customers.size(),res=0,start=0;
        for(int i=0;i<n;i++){
            if(!grumpy[i]){
                sum+=customers[i];
                customers[i]=0;
            }
        }
        res=sum;
        
        for(int i=0;i<n;i++){
            sum+=customers[i];
            if(i-start==minutes){
                sum-=customers[start];
                start++;
            }
            res=max(res,sum); 
        }
        return res;
    }
};