class Solution {
public:
    string countAndSay(int n) {
    	string ans = "1";
    	for(int i = 1; i < n; ++i){
    		ans = say(ans);
    	}
    	return ans;
    }
private:
	string say(const string& n){
		string ans;
		int s = 0;
		int l = n.length();
		for(int e = 1; e <= l; ++e){
			if(e == l || n[s] != n[e]){
				int count = e - s;
				ans += '0' + count;
				ans += n[s];
				s = e;
			}
		}
		return ans;
	}
};