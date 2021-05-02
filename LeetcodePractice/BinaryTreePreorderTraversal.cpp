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
    vector<int> preorderTraversal(TreeNode* root) {
    	vector<int> ans;
    	stack<TreeNode*> s;
    	if(root) s.push(root);
    	while(!s.empty()){
    		TreeNode* n = s.top();
    		ans.push_back(n -> val);
    		s.pop();
    		if(n -> right) s.push(n -> right);
    		if(n -> left) s.push(n -> left);
    	}
    	return ans;
    }
};