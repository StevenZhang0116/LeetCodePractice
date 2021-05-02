class Solution {
public:
    vector<int> constructArray(int n, int k) {
    	vector<int> ans;
    	int l = 1; 
    	int r = k + 1;
    	while(l <= r){
    		ans.push_back(l++);
    		if(l <= r) ans.push_back(r--);
    	}
    	for(int i = k + 2; i <= n; i++){
    		ans.push_back(i);
    	}
    	return ans;
    }
};


// LeetCode Solution 0ms

// class Solution {
// public:
//     vector<int> constructArray(int n, int k) {
//         vector<int> res;
//         int i=1,f=0,f2=0;
//         while(res.size()!=n){
//             res.push_back(i);
//             if(f==0&&k!=0){
//                 i+=k;
//                 k--;
//                 f=1;
//             }
//             else if(f==1&&k!=0){
//                 i-=k;
//                 k--;
//                 f=0;
//             }
            
//             else{
//                if(f2==0){
//                    i=res[1];
//                    f2=1;
//                }
                
//                 i++;
//             }
//         }
//         return res;
//     }
// };