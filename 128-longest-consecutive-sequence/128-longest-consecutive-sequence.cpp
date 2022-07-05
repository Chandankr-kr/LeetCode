class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==1)
            return 1;
        priority_queue<int,vector<int>,greater<int>> pq1;
        int res=0,cnt=1,flag=0,temp;
        for(auto &it:nums){
            pq1.push(it);
        }
        
        while(pq1.size()){
            if(!flag){
                temp=pq1.top();
                pq1.pop();
                flag=1;
            }
            
            if(pq1.top()==temp+1 or pq1.top()==temp){
                if(pq1.top()!=temp)
                    cnt++;
                temp=pq1.top();
                pq1.pop();
            }
            else{
                cnt=1;
                temp=pq1.top();
                pq1.pop();
            }
            // cout<<cnt<<" ";
                
            res=max(res,cnt);
        }
        return res;
    }
};