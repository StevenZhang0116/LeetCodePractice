class Solution {
public:
    string removeDuplicates(string s, int k) {
    	vector<pair<char, int>> st{{'*', 0}};
    	for(char c: s){
    		if(c != st.back().first){
    			st.emplace_back(c, 1);
    		}
    		else if(++st.back().second == k){
    			st.pop_back();
    		}
    	}
    	string ans;
		for(const auto& p: st){
			ans.append(p.second, p.first);
		}
		return ans;
    }
};