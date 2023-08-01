class Solution {
public:
    vector<int> temp;
    set<vector<int>> s1;
    vector<vector<int>> res;
    
    void findSol(int start,int end,int k){
        if(temp.size()==k){
            sort(temp.begin(),temp.end());
            s1.insert(temp);
            return;
        }    
        
        for(int i=start;i<=end;i++){
            temp.push_back(i);
            findSol(i+1,end,k);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        findSol(1,n,k);
        for(auto it:s1){
            res.push_back(it);
        }
        return res;
    }
};