class Solution {
public:
	string multiply(string num1, string num2) {
		const int l1 = num1.length();
		const int l2 = num2.length();
		string ans(l1 + l2, '0');
		for (int i = l1 - 1; i >= 0; --i){
			for (int j = l2 - 1; j >= 0; --j) {
				int sum = (ans[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0');        
				ans[i + j + 1] = (sum % 10) + '0';
				ans[i + j] += sum / 10;
			}
		}
		for (int i = 0; i < ans.length(); ++i){
			if (ans[i] != '0' || i == ans.length() - 1) {
				return ans.substr(i);
			}
		}
		return "";
	}
};