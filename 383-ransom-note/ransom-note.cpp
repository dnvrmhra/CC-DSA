class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int tally[26]={0};
        for (char ch : magazine){
            tally[ch-'a']++;
        }
        for (char ch : ransomNote){
            if (tally[ch-'a']==0)
                return false;
            tally[ch - 'a']--;
        }
        return true;
    }
};