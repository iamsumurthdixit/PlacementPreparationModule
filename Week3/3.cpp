class Solution {
public:
    bool isValid(string s) {
        stack<char> st; 
        for(int i = 0; i < (int) s.length(); i++) {
            if((s[i]=='(') || (s[i] == '{') || (s[i] == '[')) {
                st.push(s[i]);
            }
            else {
                if(st.empty()) return false; 
                else {
                    char ch = st.top(); 
                    st.pop();
                    
                    if((s[i] == ')' && ch == '(') || (s[i] == '}' && ch == '{') || (s[i] == ']' && ch == '[')) 
                        continue; 
                    else return false; 
                }
            }
        }
        if(st.empty()) return true; 
        else return false; 
    }
};
