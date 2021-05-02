// class Solution {
// public:
//     vector<int> processQueries(vector<int>& queries, int m) {
//     	vector<int> p(m+1);
//     	iota(begin(p), end(p), -1);
//     	vector<int> ans;
//     	for(int q: queries){
//     		ans.push_back(p[q]);
//     		for(int i = 1; i <= m; ++i){
//     			if(p[i] < p[q]){
//     				++p[i];
//     			}
//     		}
//     		p[q] = 0;
//     	}
//     	return ans;
//     }
// };

class Fenwick{
public: 
	explicit Fenwick(int n): vals_(n) {}

	int query(int i) const{
		int s = 0; 
		while(i > 0){
			s += vals_[i];
			i -= i & -i;
		}
		return s;
	}

	void update(int i, int delta){
		while(i < vals_.size()){
			vals_[i] += delta;
			i += i & -i;
		}
	}
private:
	vector<int> vals_;
};

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
    	Fenwick tree(m*2 + 1);
    	vector<int> pos(m+1);
    	for(int i = 1; i <= m; ++i){
    		tree.update(pos[i] = i+m, 1);
    	}
    	vector<int> ans;
    	for(int q: queries){
    		ans.push_back(tree.query(pos[q] - 1));
    		tree.update(pos[q], -1);
    		tree.update(pos[q] = m--, 1);
    	}
    	return ans;
    }
};