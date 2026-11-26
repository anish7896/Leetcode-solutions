class Solution {
public:
    bool canAliceWin(int n) {
        int x = 10;
        bool alice = true;
        while(x>0){
            if(n<x){
                return !alice;
            }
            n -= x;
            x--;
            alice = !alice;
        }
        return !alice;
    }
};