class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
    	count++;
    	d[count] = longUrl;
    	return toString(longUrl);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
    	return d[stoi[shortUrl]];
    }

private:
	int count = 0;
	map<int, string> d;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));