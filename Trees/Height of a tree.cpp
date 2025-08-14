// Q: To find max height of a binary tree.
// Intution: the idea is to store the height of left subtree and right subtree in two variables and then return the max of left anf right heights. 

// Explanation: The code returns zero when it reaches the end node. Else the left subtree will have the height of left subtree ad the right will have the height of right 
// subtree.

class Solution {
public:
    int height (TreeNode* root, int m){
        if(!root) {return 0;}

        int left = height(root->left, m);

        int right = height(root->right, m);


    

        return 1+max(left,right);
    }
    int maxDepth(TreeNode* root) {
        return height(root,0);
        
    }
};
