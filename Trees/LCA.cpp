Q: Find the least common ancestor in a tree. The least common ancestor is the closest node that share branches with the given two nodes.
Intuition: Keep traversing the tree. That is go to left and then go to right. Now at any root if the left is null then return right. If right is null return left and if
both are present then return the root. Also if root is equal to p or q then return the root itself.
The idea is if you reach a node that is either equal to p or q then we return the node then if a root gets return values from both left anf right then we return the 
current node.

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL || root == p || root == q){
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left,p,q);

        TreeNode * right = lowestCommonAncestor(root->right,p,q);

        if(left==NULL && right ){
            return right;
        }
        else if(right == NULL && left){
            return left;
        }
        else if(!left && !right) return NULL;

        else {
            return root;
        }
        
        

    }
};
