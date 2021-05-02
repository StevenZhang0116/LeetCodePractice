// class Solution {
// public:
//     int maxValue(vector<vector<int>>& events, int k) {
//     	const int n = events.size();
//     	vector<vector<int>> dp(n + 1, vector<int>(k+1));
//     	vector<int> e(n);
//     	auto comp = [](const vector<int>& a, const vector<int>& b){
//     		return a[1] < b[1];
//     	};

//     	sort(begin(events), end(events), comp);

//     	for(int i = 1; i <= n; ++i){
//     		const int p = lower_bound(begin(events), begin(events) + i, 
//     			vector<int>{0, events[i-1][0], 0}, comp) - begin(events);
//     		for(int j = 1; j <= k; ++j){
//     			dp[i][j] = max(dp[i-1][j], dp[p][j-1] + events[i-1][2]);
//     		}
//     	}
//     	return dp[n][k];
//     }
// };

#define vec vector<int>

bool comparator(vec &v1,vec &v2){
    return v1[0] < v2[0];
}
class Solution {
public:
    
    int lowerBound(vector<vec> &events, int s, int key){
        
        int e = events.size()-1;
        int ans = -1;
        while(s<=e){
            
            int mid = (s+e)/2;
            
            if(events[mid][0] <= key)
                s = mid+1;
            else{
                e = mid-1;
                ans = mid;
            }
        }
        
        return ans;
        
    }
    int fun(vector<vec> &events, int k, vector<vec> &dp, int i, int last =-1){
        int n = events.size();
        if(i == n || k <=0) return 0;
             
        if(dp[i][k] != -1) return dp[i][k];
       
        int ans = events[i][2];
        int index = lowerBound(events, i+1, events[i][1]);
        if(index != -1) ans += fun(events, k-1, dp, index);
        
       return dp[i][k] = max(ans, fun(events, k, dp, i+1));

    }
    

    int maxValue(vector<vector<int>>& events, int k) {
        
        int n = events.size();
        
        int ans = 0;
        if(k == 1){
            for(auto X : events)
                ans = max(ans, X[2]);
            
            return ans;
            
        }
        
        vector<vec> dp(n, vec(k+1, -1));
        sort(events.begin(), events.end(), comparator);
        int res = fun(events, k, dp, 0);
        return res;
    }
};