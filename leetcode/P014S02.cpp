class Solution {
private:
    string commonPrefix(string a,string b) {
        int n = a.size();
        int m = b.size();
        int size = (n<m)?n:m;
        int i;
        string ans = "";
        for(i=0;i<size;i++) {
            if(a[i] != b[i])
                break;
            else {
                ans.push_back(a[i]);
            }
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs,int left,int right) {
        if(left == right){
            return strs[left];
        }
        int mid = left + (right-left)/2;
        string lstr = longestCommonPrefix(strs,left,mid);
        string rstr = longestCommonPrefix(strs,mid+1,right);
        return commonPrefix(lstr,rstr);
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        return longestCommonPrefix(strs,0,strs.size()-1);
    }
};
