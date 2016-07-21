class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastWordCount = 0;
        if(s.size() == 0)
            return lastWordCount;
        int i=s.size()-1;
        while(s[i] == ' ' && i >= 0)
            i--;
        for(;i>=0;i--) {
            if(s[i] != ' ')
                lastWordCount++;
            else
                break;
        }
        return lastWordCount;
    }
};
