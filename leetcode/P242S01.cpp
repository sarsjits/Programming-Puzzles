class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        if(s.size() == t.size() && s.size() == 0)
            return true;
        int hash1[256] = {0};
        int hash2[256] = {0};
        for(int i=0;i<s.size();i++)
            hash1[s[i]]++;
        for(int i=0;i<t.size();i++)
            hash2[t[i]]++;
        int i;
        for(i=0;i<256;i++) {
            if(hash1[i] != hash2[i])
                break;
        }
        if(i != 256)
            return false;
        return true;
    }
};
