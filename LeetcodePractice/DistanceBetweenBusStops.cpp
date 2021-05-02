class Solution {
public:
    int distanceBetweenBusStops(vector<int>& dist, int s, int d) {
    	int n = dist.size();
    	int left = dist[d];
    	int right = 0;
    	for(int i = (s-1+n)%n; i != d; i = (i-1+n)%n) left += dist[i];
    	for(int i = s; i != d; i = (i+1)%n) right += dist[i];
    	return min(left, right);
    }
};