class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
    	int zeroCnt = 0;
    	int size = arr.size();
    	for(int i = 0; i < size; ++i){
    		if(arr[i] == 0) zeroCnt++;
    	}
    	int j = size + zeroCnt;
    	for(int i = size - 1; i >=0; --i){
    		if(--j < size) arr[j] = arr[i];
    		if(arr[i] == 0 && --j < size){
    			arr[j] = 0;
    		}
    	}
    }
};