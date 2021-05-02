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
// class Solution {
// public:
// 	int i = 0;
// 	vector<int> res;
// 	vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage){
// 		res.clear();
// 		if(dfs(root, voyage)){
// 			return res;
// 		}
// 		return {-1};
// 	}

// 	bool dfs(TreeNode* root, vector<int>& v){
// 		if(!root) return true; 
// 		if(root -> val != v[i++]) return false;
// 		if(root -> left && root -> left -> val == v[i]){
// 			return dfs(root -> left, v) && dfs(root -> right, v);
// 		}
// 		else if(root -> right && root -> right -> val == v[i]){
// 			if(root -> left){
// 				res.push_back(root -> val);
// 			}
// 			return dfs(root -> right, v) && dfs(root -> left, v);
// 		}
// 		return !root -> left && !root -> right;
// 	}

// };


class Solution {
public:
	vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
		int n = voyage.size();

		vector<int> flipped;
		int pos = 0;
		if (!helper(root, voyage, pos, flipped) || pos != n) {
			return vector<int>{-1};
		}

		return flipped;
	}
	bool helper(TreeNode* root, vector<int>& pre, int& pos, vector<int>& flipped) {
		if (!root)
			return true;
		if (root->val != pre[pos++]) {
			return false;
		}

		TreeNode* child1 = root->left, *child2 = root->right;

		// If both children are present and left node doesn't match the next element in
		// preorder traversal, process right first. If it is still a mismatch, recursive
		// call will catch it.
		if (child1 && child2 && pre[pos] != child1->val) {
			flipped.push_back(root->val);
			swap(child1, child2);
		}

		return helper(child1, pre, pos, flipped) && helper(child2, pre, pos, flipped);
	}
};