class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        long long int s1=0,s2=0,ans=0,t1=0,t2=0;
        long long int m=nums1.size(),n=nums2.size();
        vector<int> v1,v2;
        for(int i=0;i<m;i++){
            s1+=nums1[i];
        }
        
        for(int i=0;i<n;i++){
            s2+=nums2[i];
        }
        
        for(int i=0;i<m;i++){
            v1.push_back(nums2[i]-nums1[i]);
            v2.push_back(nums1[i]-nums2[i]);
        }
        long long int res1=0,res2=0;
        for(int i=0;i<m;i++){
                t1+=v1[i];
            
                res1=max(res1,t1);
            if(t1<0)
                t1=0;
            }
        
        
        for(int i=0;i<m;i++){
                t2+=v2[i];
                res2=max(res2,t2);
                 if(t2<0)
                   t2=0;
            }
        
        return max({s1,s2,s1+res1,s2+res2});
    }
};