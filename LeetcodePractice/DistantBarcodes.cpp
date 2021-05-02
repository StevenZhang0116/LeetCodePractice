class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    	constexpr int kMaxV = 10001;
    	const int n = barcodes.size();
    	vector<int> f(kMaxV);
    	int max_f = 0;
    	int max_v = 0;
    	for(int v: barcodes){
    		if(++f[v] > max_f){
    			max_f = f[v];
    			max_v = v;
    		}
    	}
    	vector<int> ans(n);
    	int pos = 0;
    	while(f[max_v]-- > 0){
    		ans[pos] = max_v;
    		if((pos += 2) >= n) pos = 1;
    	}
    	for(int v = 1; v < kMaxV; ++v){
    		while(f[v]-- > 0){
    			ans[pos] = v;
    			if ((pos += 2) >= n) pos = 1;
    		}
    	}
    	return ans;
    }
};