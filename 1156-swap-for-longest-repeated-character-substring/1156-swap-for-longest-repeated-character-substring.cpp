class Solution {
public:
    int maxRepOpt1(string text) {
        int n=text.size();
        int res=1;
        vector<int> left(n,1),right(n,1),v1(26,0);
        
        for(int i=0;i<n;i++){
            v1[text[i]-'a']++;
        }
        
        for(int i=1;i<n;i++){
            if(text[i-1]==text[i])
                left[i]=1+left[i-1];
            res=max(res,left[i]);
        }
        
        // cout<<endl;
        for(int i=n-2;i>=0;i--){
            if(text[i]==text[i+1])
                right[i]=right[i+1]+1;
            res=max(res,right[i]);
        }
        
        for(int i=1;i<n-1;i++){
            if(text[i-1]==text[i] and text[i]==text[i+1])
                res=max(res,left[i-1]+right[i+1]+1);
            else if((text[i-1]==text[i+1]) and text[i]!=text[i+1]){
                if((v1[text[i-1]-'a']-left[i-1]-right[i+1])>0)
                    res=max(res,left[i-1]+right[i+1]+1);
                else{
                    res=max(res,left[i-1]+right[i+1]);
                }
            }
            else if((text[i-1]==text[i]) and text[i]!=text[i+1]){
                res=max(res,left[i-1]+1);
            }
            else if((text[i]==text[i+1]) and text[i]!=text[i-1]){
                res=max(res,1+right[i+1]);
            }
            else{
                   
            }
            
            if(text[i-1]!=text[i]){
                    if(v1[text[i-1]-'a']-left[i-1]>0)
                        res=max(res,1+left[i-1]);
                }
                
                if(text[i+1]!=text[i]){
                    if(v1[text[i+1]-'a']-right[i+1]>0)
                        res=max(res,1+right[i+1]);
                }
        }
        return res;
    }
};