// class Solution {
// public:
//     int countBinarySubstrings(string s) {
//     	vector<int> lens(128,0);
//     	int i = 0; 
//     	int l = 0; 
//     	int ans = 0;
//     	while(true){
//     		while(i < s.length() && s[i] == s[l]) ++i;
//     		lens[s[l]] = i - l;
//     		ans += min(lens['0'], lens['1']);
//     		if(i == s.length()) break; 
//     		lens[s[i]] = 0;
//     		l = i;
//     	}
//     	return ans;
//     }
// };


class Solution {
public:
    int countBinarySubstrings(string s) {
        int cur = 1, pre = 0, res = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) cur++;
            else {
                res += min(cur, pre);
                pre = cur;
                cur = 1;
            }
        }
        return res + min(cur, pre);
    }
};