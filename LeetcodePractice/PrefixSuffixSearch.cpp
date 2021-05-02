class WordFilter {
public:
    WordFilter(vector<string>& words) {
    	int index = 0;
    	for(const string& word: words){
    		int n = word.length();
    		vector<string> prefixes(n+1, "");
    		vector<string> suffixes(n+1, "");
    		for(int i = 0; i < n; ++i){
    			prefixes[i+1] = prefixes[i] + word[i];
    			suffixes[i+1] = word[n-i-1] + suffixes[i];
    		}

    		for(const string& prefix: prefixes){
    			for(const string& suffix: suffixes){
    				filters_[prefix + "_" + suffix] = index;
    			}
    		}
    		++index;
    	}
    }
    
    int f(string prefix, string suffix) {
    	const string key = prefix + "_" + suffix;
    	auto it = filters_.find(key);
    	if(it != filters_.end()) return it->second;
    	return -1;
    }

private:
	unordered_map<string, int> filters_;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */