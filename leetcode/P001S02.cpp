#include <algorithm>

struct se {
  int x;
  int y;
  
  bool operator<(se b) const {
      return x < b.x;
  }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int size = nums.size();
        se arr[size];
        for(int i=0;i<size;i++) {
            arr[i].x = nums[i];
            arr[i].y = i;
        }
        sort(arr,arr+size);
        for(int i=0;i<size;i++) {
            cout << arr[i].x << " " << arr[i].y << "\n";
        }
        int start = 0;
        int end = nums.size() - 1;
        for(int i=0;i<size;i++) {
            if(arr[start].x+arr[end].x == target) {
                res.push_back(arr[start].y);
                res.push_back(arr[end].y);
                break;
            } else {
                if(arr[start].x+arr[end].x > target)
                    end--;
                else
                    start++;
            }
        }
        return res;
    }
};
