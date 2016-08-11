class Solution {
public:
    int titleToNumber(string s) {
        long long int ans = 0;
        for(int i=0;i<s.size();++i) {
            int n = (s[i] - 'A' + 1);
            ans = ans*26 + n;
        }
        return ans;
    }
};
