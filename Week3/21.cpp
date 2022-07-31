class Solution {
public:
    string countAndSay(int n) {
        string s = "1"; 
        while(n > 1) {
            string res; 
            map<char, int> m; 
            for(int i = 0; i < s.size(); i++) {
                m[s[i]]++; 
                if(m.size() > 1) {
                    m.erase(s[i]); 
                    for(auto it : m) {
                        res += to_string(it.second); 
                        res += it.first; 
                    }
                    m.clear(); 
                    m[s[i]]++; 
                } 
                if(i == s.size() - 1) {
                    for(auto it : m) {
                        res += to_string(it.second); 
                        res += it.first; 
                    }
                }
            }
            s = res; n--; 
        }
        return s; 
    }
};
