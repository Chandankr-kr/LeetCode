class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(),res=0;
        stack<int> s1;
        vector<int> left,right;
        for(int i=n-1;i>=0;i--){
            if(s1.size()==0){
                right.push_back(n);
                s1.push(i);
            }
            else{
                while(s1.size() and heights[i]<=heights[s1.top()]){
                    s1.pop();
                }
                if(s1.size()){
                    right.push_back(s1.top());
                }
                else{
                    right.push_back(n);
                }
                s1.push(i);
            }
        }
        
        while(s1.size())
            s1.pop();
        
        for(int i=0;i<n;i++){
            if(s1.size()==0){
                left.push_back(-1);
                s1.push(i);
            }
            else{
                while(s1.size() and heights[i]<=heights[s1.top()]){
                    s1.pop();
                }
                if(s1.size()){
                    left.push_back(s1.top());
                }
                else{
                    left.push_back(-1);
                }
                s1.push(i);
            }
        }
        reverse(right.begin(),right.end());
        
        for(int i=0;i<n;i++){
            int temp=(right[i]-left[i]-1)*heights[i];
            res=max(res,temp);
        }
        
        return res;
    }
};