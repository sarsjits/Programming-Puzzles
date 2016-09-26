class NumArray {
public:
    vector<int> extra;
    NumArray(vector<int> &nums) {
        int sum = 0;
        extra.push_back(sum);
        for(auto val: nums) {
            sum += val;
            extra.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return extra[j+1]-extra[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
