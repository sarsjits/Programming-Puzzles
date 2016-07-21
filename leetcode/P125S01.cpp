class Solution {
public:
    bool isAlphanumeric(char c) {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            return true;
        return false;
    }
    bool isEqual(char a, char b) {
        if(a >= '0' && a <= '9')
            return a == b;
        else if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) {
            if(a >= 'a')
                a = a - 'a' + 'A';
            if(b >= 'a')
                b = b - 'a' + 'A';
            return a == b;
        }
        else
            return a == b;
    }
    bool isPalindrome(string s) {
        if(s.size() == 0)
            return true;
        int x = 0, y = s.size() - 1;
        while(x < y) {
            while(isAlphanumeric(s[x]) != true && x < y) x++;
            while(isAlphanumeric(s[y]) != true && x < y) y--;
            if(isEqual(s[x],s[y]) != true)
                break;
            x++;
            y--;
        }
        if((x < y) && (s[x] != s[y]))
            return false;
        else
            return true;
    }
};
