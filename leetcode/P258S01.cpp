class Solution {
public:
    int newNum(int num) {
        int sum = 0;
        while(num > 0) {
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    int addDigits(int num) {
        while(num/10 > 0) {
            num = newNum(num);
        }
        return num;
    }
};
