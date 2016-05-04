#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int,int> arr;
        arr.clear();
        int size = nums.size();
        for(int i=0;i<size;i++) {
            arr[nums[i]] = i;
        }
        for(int i=0;i<size;i++) {
            if(arr.find(target-nums[i]) != arr.end()) {
                if(i < arr[target-nums[i]]) {
                    res.push_back(i);
                    res.push_back(arr[target-nums[i]]);
                    break;
                } 
                if(i > arr[target-nums[i]]){
                    res.push_back(arr[target-nums[i]]);
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};
