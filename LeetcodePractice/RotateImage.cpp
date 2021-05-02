// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//     	const int n = matrix.size();
//     	for(int i = 0; i < n; ++i){
//     		for(int j = i + 1; j < n; ++j){
//     			swap(matrix[i][j], matrix[j][i]);
//     		}
//     	}
//     	for(int i = 0; i < n; ++i){
//     		reverse(begin(matrix[i]), end(matrix[i]));
//     	}
//     }
// };


class Solution {
public:
    void reversecol(vector<vector<int>>& a, int c){
        int s=0, e=a.size()-1;
        while(s<e){
            swap(a[c][s], a[c][e]);
            s++;
            e--;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row==0)
            return ;
        
        int col = matrix[0].size();
        if(col==0)
            return ;
        
      
        for(int i = 0; i<row; i++)
        {
            for(int j = i; j<col; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
            
        }
        
        for(int i = 0; i<row; i++){
            reversecol(matrix, i);
        }
       
        return ;
    }
};