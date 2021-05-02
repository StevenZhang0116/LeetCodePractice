/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
    	prev_ = nullptr;
    	return inOrder(root);
    }
private:
	TreeNode* prev_;
	bool inOrder(TreeNode* root){
		if(!root) return true;
		if(!inOrder(root -> left)) return false; 
		if(prev_ && root -> val <= prev_ -> val) return false;
		prev_ = root;
		return inOrder(root -> right);
	}
};