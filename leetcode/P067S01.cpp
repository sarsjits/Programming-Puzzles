class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() == 0) return b;
        if(b.size() == 0) return a;
        if(a.size() < b.size()) return addBinary(b,a);
        int carry = 0;
        int curSum = 0;
        int i,j;
        for(i=a.size()-1,j=b.size()-1;i>=0 && j>=0;--i,--j) {
            curSum = (a[i]-'0') ^ (b[j]-'0') ^ carry;
            carry = ((a[i]-'0') & (b[j]-'0')) | ((b[j]-'0') & carry) | (carry & (a[i]-'0'));
            a[i] = char(curSum + '0');
        }
        while(carry == 1 && i >= 0) {
            curSum = (a[i]-'0') ^ carry;
            carry = (carry & (a[i]-'0'));
            a[i] = char(curSum + '0');
            if(carry == 0) break;
            i--;
        }
        if(carry == 1)
            return "1"+a;
        return a;
    }
};
