class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s1;
        queue<string> q1;
        for(auto it:wordList){
            s1.insert(it);
        }
        if(beginWord==endWord or s1.find(endWord)==s1.end())
            return 0;
        int cnt=0;
        q1.push(beginWord);
        while(q1.size()){
            cnt++;
            int n=q1.size();
            for(int i=0;i<n;i++){
                string str=q1.front();
                q1.pop();
                
                for(int j=0;j<str.size();j++){
                    char temp=str[j];
                    for(char k='a';k<='z';k++){
                        str[j]=k;
                        if(endWord==str)
                            return cnt+1;
                        else if(s1.find(str)!=s1.end()){
                            q1.push(str);
                            s1.erase(str);
                        }
                    }
                    str[j]=temp;
                }
            }
        }
        return 0;
    }
};