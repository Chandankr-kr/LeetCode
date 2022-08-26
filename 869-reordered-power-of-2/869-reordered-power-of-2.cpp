class Solution {
public:
    vector<string> res;
    void findSol(string str,int start,int end){
        if(start==end){
            res.push_back(str);
        }
        else{
            for(int i=start;i<=end;i++){
                swap(str[start],str[i]);
                findSol(str,start+1,end);
                swap(str[start],str[i]);
            }
        }
    }
    
    bool solve(int x){
        return x && (!(x&(x-1)));
    }
    
    bool reorderedPowerOf2(int n) {
        string str=to_string(n);
        int p=str.size();
        findSol(str,0,p-1);
        // for(int i=0;i<res.size();i++)
        //     cout<<res[i]<<" ";
        for(int i=0;i<res.size();i++)
            if(res[i][0]!='0' and solve(stoi(res[i])))
                return true;
        return false;
    }
};