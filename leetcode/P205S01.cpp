class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> m;
        set<char> se;
        for(int i=0;i<s.size();i++) {
            if(m.find(s[i]) == m.end()) {
                if(se.find(t[i]) == se.end()) {
                    se.insert(t[i]);
                } else {
                    return false;
                }
                m[s[i]] = t[i];
            }
            else if(m[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};
