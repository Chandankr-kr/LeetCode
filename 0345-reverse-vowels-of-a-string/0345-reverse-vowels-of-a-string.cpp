class Solution {
public:
    string reverseVowels(string s) {
        vector<char> temp;
        map<int,char> mp;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U'){
                mp[i]=s[i];
                temp.push_back(s[i]);
            }
        }
        reverse(temp.begin(),temp.end());
        for(auto it:mp){
            s[it.first]=temp[j++];
        }
        return s;
    }
};