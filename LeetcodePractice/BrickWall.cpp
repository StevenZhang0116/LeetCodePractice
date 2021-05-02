// class Solution {
// public:
//     int leastBricks(vector<vector<int>>& wall) {
//     	unordered_map<int, int> count;
//     	int max_count = 0;
//     	for(const auto& bricks: wall){
//     		int s = 0;
//     		for(int i = 0; i < bricks.size() - 1; ++i){
//     			s += bricks[i];
//     			max_count = max(max_count, ++count[s]);
//     		}
//     	}
//     	return wall.size() - max_count;
//     }
// };

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> my_map;
        int m = wall.size();
        for (int i = 0; i < m; i++) {
            int pos = 0;
            for (int j = 0; j < wall[i].size() - 1; j++) {
                pos += wall[i][j];
                my_map[pos]++;
            }
        }
        int max_pos = 0;
        for (auto& item : my_map) {
            max_pos = max(max_pos, item.second);
        }
        return m - max_pos;        
    }
};