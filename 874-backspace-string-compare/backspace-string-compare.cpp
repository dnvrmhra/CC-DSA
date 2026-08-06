class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.length()-1;
        int j=t.length()-1;
        while (i>=0 || j>=0){
            int back=0;
            while (i>=0){
                if (s[i]=='#'){
                    back++;
                    i--;
                }
                else if (back>0){
                    back--;
                    i--;
                }
                else{
                    break;
                }
            }
            back=0;
            while (j>=0){
                if (t[j]=='#'){
                    back++;
                    j--;
                }
                else if (back>0){
                    back--;
                    j--;
                }
                else {
                    break;
                }
            }
            if (i>=0 && j>=0){
                if (s[i]!=t[j])
                    return false;
            }
            else if (i>=0 || j>=0){
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
};