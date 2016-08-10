class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
        while(n>0) {
            int rem = n % 26;
            if(rem == 0) {
                s = "Z" + s;
                n = (n/26) - 1;
            } else {
                char c = char((int)('A') + rem - 1);
                string sNew(1,c);
                s = sNew + s;
                n /= 26;
            }
        }
        return s;
    }
};
