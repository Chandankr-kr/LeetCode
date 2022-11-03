class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> count;
        for(auto word:words)
            count[word]++;
        int ans=0;
        bool flag=false;
        for(auto pr:count)
        {
            string str=pr.first;
            int cnt=pr.second;
            if(str[0]==str[1])
            {
                if(cnt&1)
                {
                    ans+=(cnt-1)*2;
                    flag=true;
                }
                else
                    ans+=cnt*2;
            }
            else
            {
                string rev=str;
                swap(rev[0],rev[1]);
                int cnt1=count[rev];
                ans+=min(cnt,cnt1)*2;
            }
        }
      return flag==true?ans+2:ans;
    }
};