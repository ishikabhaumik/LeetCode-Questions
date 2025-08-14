Q: At any node the height of the left subtree and right subtreee should not differ more than 1

Intution: Same as max height of a tree try to find the height of left and right subtree and then keep a check if the height difference is more than 1. 

Explanation: Keep traversing left for hegiht of left tree. Keep traversing roght for the right subtree. Now check if left- right height is more than 1 then return -1. Also check if 
left or right is individuallt -1 then that means some subtree has a height difference greater than 1. 
Else keep returning the max of left and right and a +1.

class Solution {
public:
    int Balanced(TreeNode* root){
        if(!root) return 0;

        int left= Balanced(root->left);
        int right = Balanced ( root ->right);
        if(abs(left-right)>1) return -1;
        if(left==-1 || right == -1) return -1;
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        int max= Balanced(root);

        return max>-1;

        
        
    }
};
