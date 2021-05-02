class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
    	vector<int> req(26);
    	for(const string& b: B){
    		vector<int> cur(getCount(b));
    		for(int i = 0; i < 26; ++i){
    			req[i] = max(req[i], cur[i]);
    		}
    	}

    	vector<string> ans;
    	for(const string& a: A){
    		vector<int> cur(getCount(a));
    		bool universal = true;
    		for(int i = 0; i < 26; ++i){
    			if(cur[i] < req[i]){
    				universal = false; 
    				break;
    			}
    		}
    		if(universal) ans.push_back(a);
    	}

    	return ans;
    }

private:
	vector<int> getCount(const string& a){
		vector<int> count(26);
		for(char c: a){
			++count[c - 'a'];
		}
		return count;
	}
};