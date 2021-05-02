class Solution {
public:
    string strWithout3a3b(int A, int B) {
    	char a = 'a';
    	char b = 'b';
    	if(B > A){
    		swap(A,B);
    		swap(a,b);
    	}
    	string ans;
    	while(A || B){
    		if(A > 0) {ans += a; --A;}
    		if(A > B) {ans += a; --A;}
    		if(B > 0) {ans += b; --B;}
    	}
    	return ans;
    }
};