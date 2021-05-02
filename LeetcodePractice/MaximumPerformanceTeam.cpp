class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    	vector<pair<int, int>> es;
    	for(int i = 0; i < n; ++i){
    		es.push_back({efficiency[i], speed[i]});
    	}
    	sort(rbegin(es), rend(es));
    	priority_queue<int, vector<int>, greater<int>> q;
    	long sum = 0;
    	long ans = 0;
    	for(int i = 0; i < n; ++i){
    		if(i >= k){
    			sum -= q.top();
    			q.pop();
    		}
    		sum += es[i].second;
    		q.push(es[i].second);
    		ans = max(ans, sum * es[i].first);
    	}
    	return ans % static_cast<int>(1e9 + 7);
    }
};