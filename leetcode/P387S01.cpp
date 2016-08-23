class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> unMap;
        for(int i=0;i<s.size();++i) {
            if(unMap.find(s[i]) == unMap.end()) {
                unMap[s[i]] = 1;
            } else {
                unMap[s[i]]++;
            }
        }
        for(int i=0;i<s.size();++i) {
            if(unMap[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
