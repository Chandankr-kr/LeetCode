class Solution {
public:
    set<int> s1;
    void findSol(TreeNode* root){
        if(!root)
            return;
        s1.insert(root->val);
        findSol(root->left);
        findSol(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        findSol(root);
        int cnt=0;
        for(auto &it:s1){
            cnt++;
            if(cnt==2)
                return it;
        }
        return -1;
    }
};