class Solution {
public:
    int longestValidParentheses(string s) {
    	stack<int> q;
    	int start = 0;
    	int ans = 0;
    	for(int i = 0; i < s.length(); i++){
    		if(s[i] == '('){
    			q.push(i);
    		}
    		else{
    			if(q.empty()){
    				start = i + 1;
    			}
    			else{
    				int index = q.top();
    				q.pop();
    				ans = max(ans, q.empty() ? i - start + 1 : i - q.top());  
    			}
    		}
    	}
    	return ans;
    }
};