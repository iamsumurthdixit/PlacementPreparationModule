class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a(26), b(26); 
        for(char x : s) {
            a[x-'a']++; 
        }
        for(char x : t) {
            b[x -'a']++; 
        }
        for(int i =0 ; i < 26; i++) {
            if(a[i] != b[i]) {
                return false; 
            }
        }
        return true; 
    }
};
