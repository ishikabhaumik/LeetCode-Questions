#Level order traversal.
# The idea is to take a queue and pop nodes from the queue and simultaneously push its left and right child.

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int> level;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node!=NULL){
                level.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            else if(!q.empty()){
                ans.push_back(level);
                q.push(NULL);
                level.clear();
            }

        }
        ans.push_back(level);
                return ans;
    }
};
