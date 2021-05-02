class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
    	int N = rooms.size();
    	vector<int> visited(N);
    	dfs(visited, rooms, 0);
    	int res = 0;
    	for(int v: visited) res += v;
    	return res == N;
    }
private:
	void dfs(vector<int>& visited, vector<vector<int>>& rooms, int pos){
		visited[pos] = 1;
		for(int n: rooms[pos]){
			if(!visited[n]){
				dfs(visited, rooms, n);
			}
		}
	}
};