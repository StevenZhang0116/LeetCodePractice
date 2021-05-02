#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
    	if (s.length() == 0){
    		return 0;
    	}
    	int left = 0;
    	int right = s.length() - 1;
    	while (left < right){
    		if (s.at(left) == s.at(right)){
    			left += 1;
    			right -= 1;
    		}
    		else {
    			return 2;
    		}
    	}
    	return 1;
    }
};

int main(){
	char s[1000];
	Solution theSolution;

	cin >> s;
	cout << theSolution.removePalindromeSub(s) << endl;
}
