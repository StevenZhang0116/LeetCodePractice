class Solution {
public:
    int mirrorReflection(int p, int q) {
    	return 1 - p / gcd(p, q) % 2 + q / gcd(p, q) % 2;
    }

    int gcd(int p, int q){
    	return q ? gcd(q, p % q) : p;
    }
};