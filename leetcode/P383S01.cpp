class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> Map;
        for(char c: magazine) {
            if(Map.find(c) == Map.end()) {
                Map[c] = 1;
            } else {
                Map[c]++;
            }
        }
        for(char c: ransomNote) {
            if(Map.find(c) != Map.end()) {
                if(Map[c] == 0)
                    return false;
                else
                    Map[c]--;
            } else {
                return false;
            }
        }
        return true;
    }
};
