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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    	return helper(pre, 0, (int)pre.size()-1, post, 0, (int)post.size()-1);
    }

    TreeNode* helper(vector<int>& pre, int preL, int preR, vector<int>& post, int postL, int postR){
    	if (preL > preR || postL > postR){
    		return nullptr;
    	}
    	TreeNode *node = new TreeNode(pre[preL]);
    	if(preL == preR){
    		return node;
    	}
    	int idx = -1;
    	for(idx = postL; idx <= postR; ++idx){
    		if(pre[preL + 1] == post[idx]){
    			break;
    		}
    	}
    	node -> left = helper(pre, preL + 1, preL + 1 + (idx - postL), post, postL, idx);
    	node -> right = helper(pre, preL + 1 + (idx - postL) + 1, preR, post, idx + 1, postR - 1);
    	return node;
    }

};