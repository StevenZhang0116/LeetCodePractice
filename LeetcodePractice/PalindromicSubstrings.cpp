// class Solution {
// public:
//     int countSubstrings(string s) {
//     	const int N = s.size();
//     	vector<vector<int>> dp(N, vector<int>(N, false));
//     	int count = 0; 
//     	for(int l = 1; l <= N; ++l){
//     		for(int i = 0; i <= N-l; ++i){
//     			int j = i + l - 1;
//     			if(l == 1 || (l == 2 && s[i] == s[j]) || (l >= 3 && s[i] == s[j] && dp[i+1][j-1])){
//     				count ++;
//     				dp[i][j] = true;
//     			}
//     		}
//     	}
//     	return count;
//     }
// };


class Solution {
// https://leetcode.com/problems/palindromic-substrings/solution/
 public:
    int countSubstrings(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); ++i) {
            // odd-length palindromes, single character center
            ans += countPalindromesAroundCenter(s, i, i);

            // even-length palindromes, consecutive characters center
            ans += countPalindromesAroundCenter(s, i, i + 1);
        }

        return ans;
    }

    int countPalindromesAroundCenter(const string& ss, int lo, int hi) {
        int ans = 0;

        while (lo >= 0 and hi < ss.size()) {
            if (ss[lo] != ss[hi])
                break;      // the first and last characters don't match!

            // expand around the center
            lo--;
            hi++;

            ans++;
        }

        return ans;
    }
};