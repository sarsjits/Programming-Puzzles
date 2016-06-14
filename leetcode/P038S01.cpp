class Solution {
private:
    string getNext(const string& str) {
        string next_seq = "";
        for(auto i=str.cbegin();i!=str.cend();) {
            auto j = find_if(i,str.cend(),bind1st(not_equal_to<char>(), *i));
            next_seq.append(to_string(distance(i,j)));
            next_seq.push_back(*i);
            i = j;
        }
        return next_seq;
    }
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        if(n == 2) return "11";
        string next_seq{"11"};
        for(int i=3;i<=n;i++) {
            next_seq = getNext(next_seq);
        }
        return next_seq;
    }
};
