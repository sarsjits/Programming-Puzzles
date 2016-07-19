class Solution {
public:
    int findCandidate(vector<int>& arr) {
        int majIdx = 0, count = 1;
        for(int i=1;i<arr.size();i++) {
            if(arr[majIdx] == arr[i]) {
                count++;
            } else {
                count--;
            }
            if(count == 0) {
                majIdx = i;
                count = 1;
            }
        }
        return arr[majIdx];
    }
    int majorityElement(vector<int>& nums) {
        int possibleMajorityElement = findCandidate(nums);
        return possibleMajorityElement;
    }
};
