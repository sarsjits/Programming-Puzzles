// Time: O(n)
// Space: O(n)

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int n = s.size();
        bool down = true;
        string arr[numRows];
        int row = 0;
        for(int i=0;i<n;i++) {
            arr[row].push_back(s[i]);
            if(row == numRows-1)
                down = false;
            if(row == 0)
                down = true;
            if(down == true)
                row++;
            else
                row--;
        }
        string str = "";
        for(int i=0;i<numRows;i++)
            str = str + arr[i];
        return str;
    }
};
