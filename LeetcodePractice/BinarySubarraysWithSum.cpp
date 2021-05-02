class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
    	int res = 0;
    	int sum = 0;
    	int left = 0;
    	int n = A.size();

    	for(int i = 0; i < n; ++i){
    		sum += A[i];
    		while (left < i && sum > S) sum -= A[left++];
    		if (sum < S) continue;
    		if (sum == S) ++res;
    		for(int j = left; j < i && A[j] == 0; ++j){
    			++res;
    		}
    	}

    	return res;
    }
};