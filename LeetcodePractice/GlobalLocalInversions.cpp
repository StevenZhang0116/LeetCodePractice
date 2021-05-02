// class Solution {
// public:
//     bool isIdealPermutation(vector<int>& A) {
//     	for(int i = 0; i < A.size(); ++i){
//     		if(abs(A[i] - i) > 1) return false;
//     	}
//         return true;
//     }
// };


// MergeSort
class Solution {
public:
  bool isIdealPermutation(vector<int>& A) {
    const int n = A.size();
    int local = 0;
    for (int i = 0; i < n - 1; ++i)
      if (A[i] > A[i + 1]) ++local;
    tmp = vector<int>(n);
    int global = mergeSort(A, 0, n - 1);
    return global == local;
  }
private:
  vector<int> tmp;
  int mergeSort(vector<int>& A, int l, int r) {
    if (l >= r) return 0;
    const int len = r - l + 1;
    int m = (r - l) / 2 + l;
    int inv = mergeSort(A, l, m) + mergeSort(A, m + 1, r);
        
    int i = l;
    int j = m + 1;
    int k = 0;
    
    while (i <= m && j <= r) {
      if (A[i] <= A[j]) {
        tmp[k++] = A[i++];
      } else {
        tmp[k++] = A[j++];
        inv += m - i + 1;
      }
    }
    
    while (i <= m) tmp[k++] = A[i++];
    while (j <= r) tmp[k++] = A[j++];
    
    std::copy(tmp.begin(), tmp.begin() + len, A.begin() + l);
    
    return inv;
  }
};