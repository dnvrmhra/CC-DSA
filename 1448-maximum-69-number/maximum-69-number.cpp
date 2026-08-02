class Solution {
public:
    int maximum69Number(int num){
        int temp=num;
        int pos=-1;
        int place=1;
        while (temp>0){
            if (temp%10==6){
                pos=place;
            }
            temp/=10;
            place*=10;
        }
        if (pos!=-1){
            num+=3*pos;
        }
        return num;
    }
};
