class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> sVector = split(str,' ');
        if(pattern.size() != sVector.size()) return false;
        map<char,string> m;
        set<string> s;
        for(int i=0;i<pattern.size();++i) {
            if(m.find(pattern[i]) == m.end()) {
                m[pattern[i]] = sVector[i];
                if(s.find(sVector[i]) != s.end())
                    return false;
                s.insert(sVector[i]);
            } else if(m[pattern[i]] != sVector[i]) {
                return false;
            }
        }
        return true;
    }
    vector<string> split(string str, char delimiter) {
        vector<string> internal;
        stringstream ss(str);
        string tok;
        
        while(getline(ss, tok, delimiter)) {
            internal.push_back(tok);
        }
        return internal;
    }
};
