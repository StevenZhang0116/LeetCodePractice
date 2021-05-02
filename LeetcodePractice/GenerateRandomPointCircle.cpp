class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
    	rad = radius;
    	x = x_center; 
    	y = y_center;
    }
    
    vector<double> randPoint() {
    	const double PI = 3.141592653;
    	double nr = sqrt(rand() / double(RAND_MAX)) * rad;
    	double alpha = rand() / double(RAND_MAX) * 2 * PI;
    	double nx = x + nr * cos(alpha);
    	double ny = y + nr * sin(alpha);
    	return {nx, ny};
    }
private:
	double rad;
	double x, y;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */