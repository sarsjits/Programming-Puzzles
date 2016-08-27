class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // First shift m elements present in vector 1 to the last
        if(n == 0)
            return;
        if(m == 0) {
            nums1 = nums2;
            return;
        }
        for(int i=m-1;i>=0;--i) {
            nums1[i+n] = nums1[i];
        }
        
        int i = n; // For current vector 1
        int j = 0; // For current vector 2
        int k = 0; // For resulting vector 1
        
        while(k < m+n) {
            if((i < m+n && nums1[i] < nums2[j]) || j == n) {
                nums1[k++] = nums1[i++];
            } else {
                nums1[k++] = nums2[j++];
            }
        }
    }
};
