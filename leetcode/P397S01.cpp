class Solution {
public:
    int _result(long long n, int count) {
        if(n == 1)
            return count;
        if((n&1) == 0)
            return _result(n/2,count+1);
        else
            return min(_result(n-1,count+1),_result(n+1,count+1));
    }
    int integerReplacement(int n) {
        int count = 0;
        return _result(n,count);
    }
};
