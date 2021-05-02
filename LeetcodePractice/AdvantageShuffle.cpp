class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    	multiset<int> s(begin(A), end(A));
    	vector<int> ans;
    	for(int b: B){
    		auto it = s.upper_bound(b);
    		if(it == s.end()) it = s.begin(); 
    		ans.push_back(*it);
    		s.erase(it);
    	}
    	return ans;
    }
};