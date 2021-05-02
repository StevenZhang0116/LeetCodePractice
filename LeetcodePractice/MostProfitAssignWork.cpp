// class Solution {
// public:
//     int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
//     	const int N = 100000;
//     	vector<int> max_profit(N + 1, 0);
//     	for(int i = 0; i < difficulty.size(); ++i){
//     		max_profit[difficulty[i]] = max(max_profit[difficulty[i]], profit[i]);
//     	}
//     	for(int i = 2; i <= N; ++i){
//     		max_profit[i] = max(max_profit[i], max_profit[i - 1]);
//     	}
//     	int ans = 0;
//         for(int level: worker){
//             ans += max_profit[level];
//         }
//         return ans;
//     }
// };



class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
       // sort(w.begin(),w.end());
        int best=-1;
        int pos=-1;
        int max_profit=0;
        int max_val=0;
        for(int i=0;i<d.size();i++){
            max_val=max(max_val,d[i]);
        }
        for(int i=0;i<w.size();i++){
            max_val=max(max_val,w[i]);
        }
       
        int *ar=new int[max_val+1];
        int size=max_val+1;
        for(int i=0;i<size;i++){
            ar[i]=0;
        }
        for(int i=0;i<d.size();i++){
            ar[d[i]]=max(ar[d[i]],p[i]);
        }
    
        
        max_val=0;
        for(int i=0;i<size;i++){
            ar[i]=max(ar[i],max_val);
            max_val=max(max_val,ar[i]);
        }
        
        for(int i=0;i<w.size();i++){
            max_profit+=ar[w[i]];
        }
        return max_profit;
    }
};