class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftsum = 0, rightsum = 0, leftQues = 0, rightQues = 0;
        for(int i=0;i<n;i++){
            if(num[i]=='?'){
                if(i<n/2){
                    leftQues++;
                }
                else{
                    rightQues++;
                }
            }
            else{
                if(i<n/2){
                    leftsum += num[i]-'0';
                }
                else{
                    rightsum += num[i]-'0';
                }
            }
        }
        int totalQues = leftQues + rightQues;
        if(totalQues%2==1) return true;
        int Left = 2 * leftsum + 9*leftQues;
        int Right = 2 * rightsum + 9*rightQues;
        if(Left == Right) return false;
        return true;
    }
};