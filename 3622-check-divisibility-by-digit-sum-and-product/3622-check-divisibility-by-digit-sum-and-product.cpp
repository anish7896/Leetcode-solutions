class Solution {
public:
    bool checkDivisibility(int n) {
        int digit_sum = 0;
        int digit_product = 1;
        int temp = n;
        while(temp>0){
            int last_digit = temp%10;
            digit_sum += last_digit;
            digit_product *= last_digit;
            temp /= 10;
        }
        if(n % (digit_sum + digit_product) == 0) return true;
        return false;
    }
};