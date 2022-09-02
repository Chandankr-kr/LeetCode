class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q1;
        q1.push(root);
        while(q1.size()){
            int n=q1.size();
            double temp=0;
            for(int i=0;i<n;i++){
                auto it=q1.front();
                q1.pop();
                temp+=it->val;
                if(it->left)
                    q1.push(it->left);
                if(it->right)
                    q1.push(it->right);
            }
            res.push_back(temp/n);
        }
        return res;
    }
};