class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int cnt=0,n=row.size();
        for(int i=0;i<n;i+=2){
            int first=row[i];
            int second=first&1?first-1:first+1;
            if(row[i+1]==second)
                continue;
            for(int j=i+2;j<n;j++){
                if(second==row[j]){
                    swap(row[i+1],row[j]);
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};