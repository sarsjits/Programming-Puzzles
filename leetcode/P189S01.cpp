class Solution {
public:
    void reverse(vector<int> &a,int start,int end) {
        while(start<end) {
            int tmp = a[start];
            a[start] = a[end];
            a[end] = tmp;
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        k = len - k;
        reverse(nums,0,k-1);
        reverse(nums,k,len-1);
        reverse(nums,0,len-1);
    }
};
