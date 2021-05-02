class Solution {
public:
    int maxVowels(string s, int k) {
    	vector<int> v(128);
    	v['a'] = v['e'] = v['i'] = v['o'] = v['u'] = 1;
    	int total = 0;
    	int ans = 0; 
    	for(int i = 1; i <= s.length(); ++i){
    		total += v[s[i - 1]];
    		if(i >= k){
    			ans = max(ans, total);
    			total -= v[s[i - k]];
    		}
    	}
    	return ans;
        
    }
};