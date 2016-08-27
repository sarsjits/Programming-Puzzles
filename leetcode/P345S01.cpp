class Solution {
public:
    string reverseVowels(string s) {
        set<char> vowel;
        vowel.insert('a');
        vowel.insert('e');
        vowel.insert('i');
        vowel.insert('o');
        vowel.insert('u');
        
        vowel.insert('A');
        vowel.insert('E');
        vowel.insert('I');
        vowel.insert('O');
        vowel.insert('U');
        int start = 0;
        int end = s.length() - 1;
        while(start < end) {
            while(vowel.find(s[start]) == vowel.end()) start++;
            while(vowel.find(s[end]) == vowel.end()) end--;
            if(start < end) {
                swap(s[start],s[end]);
            } else {
                break;
            }
            start++;
            end--;
        }
        return s;
    }
};
