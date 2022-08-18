class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int cnt=0;
        queue<int> q1;
        set<int> s1;
        q1.push(start);
        while(q1.size()){
            int n=q1.size();
            cnt++;
            for(int i=0;i<n;i++){
                int temp=q1.front();
                q1.pop();
                if(temp==goal)
                    return cnt-1;
                if(temp<0 or temp>1000 or s1.count(temp))
                    continue;
                s1.insert(temp);
                for(int j=0;j<nums.size();j++){
                        q1.push(temp+nums[j]);
                        
                    
                        q1.push(temp-nums[j]);
                        
                
                        q1.push(temp^nums[j]);
                    
                            
                }
            }
        }
        return -1;
    }
};