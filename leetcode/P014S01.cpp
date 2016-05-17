class Solution {
private:
    string findCommon(string a,string b) {
        int n = a.size();
        int m = b.size();
        int size = (n<m)?n:m;
        string ans = "";
        for(int i=0;i<size;i++) {
            if(a[i] != b[i])
                break;
            else 
                ans.push_back(a[i]);
        }
        return ans;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 0)
            return ans;
        ans = strs[0];
        for(int i=1;i<strs.size();i++) {
            ans = findCommon(ans,strs[i]);
            if(ans.length() == 0)
                return "";
        }
        return ans;
    }
};
