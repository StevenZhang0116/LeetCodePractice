class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
    	int n = t.size();
    	for(int i = 0; i < n; ++i){
    		for(int j = 0; j <= i; ++j){
    			if(i == 0 && j == 0) continue; 
    			if(j == 0) t[i][j] += t[i-1][j];
    			else if(i == j) t[i][j] += t[i-1][j-1];
    			else t[i][j] += min(t[i-1][j], t[i-1][j-1]);
    		}
    	}
    	return *std::min_element(begin(t.back()), end(t.back()));
    }
};