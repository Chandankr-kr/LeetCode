class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left,right;
        stack<int> s1;
        
        for(int i=n-1;i>=0;i--){
            if(s1.size()==0){
                right.push_back(n);
            }
            else{
                while(s1.size() and heights[s1.top()]>=heights[i])
                    s1.pop();
                
                if(s1.size()==0)
                    right.push_back(n);
                else
                    right.push_back(s1.top());
            }
            s1.push(i);
        }
        
        reverse(right.begin(),right.end());
        while(s1.size())
            s1.pop();
        
        
        for(int i=0;i<n;i++){
            if(s1.size()==0){
                left.push_back(-1);
            }
            else{
                while(s1.size() and heights[s1.top()]>=heights[i])
                    s1.pop();
                
                if(s1.size()==0){
                    left.push_back(-1);
                }
                else{
                    left.push_back(s1.top());
                }
                
            }
            s1.push(i);
        }
        
        int res=0;
        // for(int i=0;i<n;i++){
        //     cout<<left[i]<<" "<<right[i]<<endl;
        // }
        for(int i=0;i<n;i++){
            res=max(res,(right[i]-left[i]-1)*heights[i]);
        }
        return res;
    }
};