Q: Is to find the diameter that is the longest path between two nodes in a binary tree.
Intution: At every node we need to claculate the sum of max heights on left and right and then try summing it up to check if that is the longest path.
Explanation: At every node return the left max depth and right max depth and then check if the sum of the heights is maximum out of all the nodes.

class Solution {
public:
    int diameter(TreeNode * root, int & m){
        if(!root) return 0;
        int left= diameter(root->left,m);

        int right = diameter(root->right,m);

        m=max(m,left+right);

        return 1+ max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int m=0;
        diameter(root,m);
        return m;
    }
};
