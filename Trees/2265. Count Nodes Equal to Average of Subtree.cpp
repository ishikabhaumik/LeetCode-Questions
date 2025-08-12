// Q: Given a Binary tree find the number of nodes which have the value same as the average of values in its subtree. 
// Intution: we have to traverse the left right subtrees and then the root node which happens in post order traversal. 
// Ans:  So we will do a recursive left and right subtree traversal and compute the count and the sum of the subtrees and then check if the average is equal to the root value.


class Solution {
public:
int count=0;
    pair<int,int> postorder ( TreeNode* root){
        if(!root) return {0,0};

        pair<int,int> left= postorder(root->left);
        pair<int,int>right= postorder(root->right);

        int nodeSum= left.first+ right.first + root->val;

        int nodeCount= left.second + right.second + 1;

        if(root->val == nodeSum/nodeCount){
            count ++;
        }

        return {nodeSum, nodeCount};
    }
    int averageOfSubtree(TreeNode* root) {
        postorder(root);

        return count;
        
    }
};
