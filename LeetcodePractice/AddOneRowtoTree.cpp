// struct TreeNode {
// 	int val;
// 	TreeNode *left;
// 	TreeNode *right;
// 	TreeNode() : val(0), left(nullptr), right(nullptr) {}
// 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// 	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

 
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
    	if (!root) return NULL;
    	if (d == 1){
    		TreeNode *newRoot = new TreeNode(v);
    		newRoot -> left = root;
    		return newRoot;
    	}

    	queue<TreeNode*> q{{root}};
    	while (!q.empty()){
    		if (--d == 0) return root;
    		int n = q.size();
    		for(int i = 0; i < n; ++i){
    			auto t = q.front();
    			q.pop();
    			if (d == 1){
    				TreeNode *left = t->left;
    				TreeNode *right = t->right;
    				t->left = new TreeNode(v);
    				t->right = new TreeNode(v);
    				t->left->left = left;
    				t->right->right = right;
    			}
    			else{
    				if (t->left) q.push(t->left);
    				if (t->right) q.push(t->right);
    			}	
    		}
    	}
    	return root;
    }
};