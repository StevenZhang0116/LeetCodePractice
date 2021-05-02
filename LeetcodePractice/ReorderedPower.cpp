// class Solution {
// public:
//     bool reorderedPowerOf2(int N) {
//     	auto m = countMap(N);
//     	for(int i = 0; i < 31; ++i){
//     		if(m == countMap(1 << i)) return true;
//     	}
//     	return false;
//     }
// private:
// 	map<int, int> countMap(int n){
// 		map<int, int> m;
// 		while(n){
// 			++m[n % 10];
// 			n /= 10;
// 		}
// 	return m;
// 	}
// };


class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string digits_required{to_string(N)};
        int power_of_2 = 1;
        bool is_p_of_2{false};
        for(int i = 0; i < 30; ++i) {
            string curr_power = to_string(power_of_2);
            if(curr_power.size() == digits_required.size()) {
                is_p_of_2 = is_p_of_2 || isSameDigits(curr_power, digits_required);
            }
            cout << power_of_2 << endl;
            power_of_2 *= 2;
        }
        return is_p_of_2;
    }
private:
    bool isSameDigits(const string& s0, const string& s1) {
        unordered_multiset<char> s0_count;
        for(int i = 0; i < s0.size(); ++i) {
            s0_count.insert(s0[i]);
        }
        for(int i = 0; i < s1.size(); ++i) {
            if(s0_count.find(s1[i]) == s0_count.end())
                return false;
            else
                s0_count.erase(s0_count.find(s1[i]));
        }
        return s0_count.size() == 0;
    }
    
};
