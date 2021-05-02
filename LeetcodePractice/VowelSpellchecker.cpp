class Solution {
public:
	vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {    
		vector<string> ans;
		unordered_map<string, string> m_org;
		unordered_map<string, string> m_low;
		unordered_map<string, string> m_vow;
		for (const string& w : wordlist) {
			m_org[w] = w;
			string l = toLower(w); 
			if (!m_low.count(l)) m_low[l] = w; 
			string o = replaceVowels(l);
			if (!m_vow.count(o)) m_vow[o] = w;
		}

		for (const string& q : queries) {      
			if (m_org.count(q)) {
				ans.push_back(q);
				continue;
			}
			string l = toLower(q);
			if (m_low.count(l)) {
				ans.push_back(m_low[l]);
				continue;
			}

			string o = replaceVowels(l);      
			if (m_vow.count(o)) {
				ans.push_back(m_vow[o]);
				continue;
			}
			ans.push_back("");
		}
		return ans;
	}
private:
	string toLower(const string& s) {
		string l(s);
		std::transform(begin(s), end(s), begin(l), ::tolower);
		return l;
	}

	string replaceVowels(const string& s) {
		string o(s);
		for (char& c : o)
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				c = '*';
		return o;
	}
};