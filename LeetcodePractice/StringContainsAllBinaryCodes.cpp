class Solution {
public:
    bool hasAllCodes(string s, int k) {
    	const int n = s.length();
    	if((n - k + 1) * k < (1 << k)){
    		return false;
    	}
    	unordered_set<string> c;
    	for(int i = 0; i + k <= n; ++i){
    		c.insert(s.substr(i, k));
    	}
    	return c.size() == (1 << k);
    }
};