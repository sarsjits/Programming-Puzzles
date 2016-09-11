class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = 0;
        int func = 0;
        int len = A.size();
        if(len == 0) return 0;
        for(int i=0;i<len;++i) {
            sum += A[i];
            func += i*A[i];
        }
        /* func is the F(0) */
        int max = func;
        for(int i=0;i<len;i++) {
            func = func + sum - len*A[len-1-i];
            if(max < func)
                max = func;
        }
        return max;
    }
};
