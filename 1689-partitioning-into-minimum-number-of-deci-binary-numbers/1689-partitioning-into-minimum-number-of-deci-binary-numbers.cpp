class Solution {
public:
    int minPartitions(string n) {
        int res=0;
        for(auto &it:n){
            res=max(res,it-'0');
        }
        return res;
    }
};