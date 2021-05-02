class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    	vector<vector<int>> g(n);
    	vector<int> ts(n, INT_MAX);
    	vector<vector<int>> ans;
    	int t = 0; 

    	function<int(int, int)> tarjan = [&](int i, int p){
    		int min_i = ts[i] = ++t;
    		for(int j: g[i]){
    			if(ts[j] == INT_MAX){
    				int min_j = tarjan(j, i);
    				min_i = min(min_i, min_j);
    				if(ts[i] < min_j){
    					ans.push_back({i, j});
    				}
    			}
				else if(j != p){
					min_i = min(min_i, ts[j]);
				}
    		}
    		return min_i;
    	};

    	for(const auto& e: connections){
    		g[e[0]].push_back(e[1]);
    		g[e[1]].push_back(e[0]);
    	}

    	tarjan(0, -1);
    	return ans;
    }
};