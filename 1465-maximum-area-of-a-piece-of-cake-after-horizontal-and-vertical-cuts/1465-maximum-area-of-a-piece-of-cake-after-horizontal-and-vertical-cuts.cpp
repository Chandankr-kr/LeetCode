class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int m=horizontalCuts.size();
        int n=verticalCuts.size();
        long long int res=0;
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        vector<long long int> left,right;
        left.push_back(horizontalCuts[0]);
        right.push_back(verticalCuts[0]);
        
        for(int i=0;i<m-1;i++){
            left.push_back(horizontalCuts[i+1]-horizontalCuts[i]);
        }
        left.push_back(h-horizontalCuts[m-1]);
            
        for(int i=0;i<n-1;i++){
            right.push_back(verticalCuts[i+1]-verticalCuts[i]);
        }
        right.push_back(w-verticalCuts[n-1]);
        
        // for(int i=0;i<left.size();i++){
        //     cout<<left[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<right.size();i++){
        //     cout<<right[i]<<" ";
        // }
        // cout<<endl;
        long long int t1=(int)*max_element(left.begin(),left.end());
        long long int t2=(int)*max_element(right.begin(),right.end());
        res=t1*t2;
        return res%(1000000000+7);
    }
};