class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<long long int> v1(n,0);
        for(auto &it:shifts){
            if(it[2]){
                v1[it[0]]++;
                v1[it[0]]%=26;
                
                if(it[1]+1<n){
                    v1[it[1]+1]--;
                    v1[it[1]+1]%=26;
                }
            }
            else{
                v1[it[0]]--;
                v1[it[0]]%=26;
                if(it[1]+1<n){
                    v1[it[1]+1]++;
                    v1[it[1]+1]%=26;
                }
            }
            
        }
        
        for(int i=1;i<v1.size();i++){
            v1[i]+=v1[i-1];
            v1[i]%=26;
        }
        
        vector<char> temp;
        for(char i='a';i<='z';i++){
            temp.push_back(i);
        }
        for(char i='a';i<='z';i++){
            temp.push_back(i);
        }
            
        for(int i=0;i<v1.size();i++){
            if(v1[i]>=0){
                int p=s[i]-97;
                s[i]=temp[p+v1[i]];
            }
            else{
                int p=s[i]-97+26;
                s[i]=temp[p+v1[i]];
            }
        }
        
        return s;
    }
};