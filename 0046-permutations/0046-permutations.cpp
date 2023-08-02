class Solution {
public:
    vector<vector<int>> res;
    void findSol(vector<int> &nums,int start,int end){
        if(start==end){
            res.push_back(nums);
            return;
        }
        
        for(int i=start;i<end;i++){
            swap(nums[i],nums[start]);
            findSol(nums,start+1,end);
            swap(nums[i],nums[start]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        findSol(nums,0,nums.size());
        return res;
    }
};