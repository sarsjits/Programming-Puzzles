class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0,count = 0;
        map<char,int> m;
        for(int i=0;i<secret.size();++i) {
            if(m.find(secret[i]) == m.end()) {
                m[secret[i]] = 1;
            } else {
                m[secret[i]]++;
            }
        }
        for(int i=0;i<guess.size();++i) {
            if(m.find(guess[i]) != m.end()) {
                if(m[guess[i]] - 1 >= 0) {
                    m[guess[i]]--;
                    count++;    
                }
            }
        }
        for(int i=0;i<secret.size();++i) {
            if(secret[i] == guess[i]) bulls++;
        }
        cows = count - bulls;
        string res = to_string(bulls) + "A" + to_string(cows) + "B";
        return res;
    }
};
