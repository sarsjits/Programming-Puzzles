class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0 || s.length() == 1)
            return s.length();
        int curLen = 1;
        int maxLen = 1;
        int *visited = new int [256];
        for(int i=0;i<256;++i)
            visited[i] = -1;
        visited[s[0]] = 0;
        for(int i=1;i<s.length();++i) {
            int prev = visited[s[i]];
            if(prev == -1 || i - curLen > prev)
                curLen++;
            else {
                if(curLen > maxLen)
                    maxLen = curLen;
                curLen = i - prev;
            }
            visited[s[i]] = i;
        }
        if(curLen > maxLen)
            maxLen = curLen;
        delete [] visited;
        return maxLen;
    }
};
