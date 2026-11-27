
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();

        while (i < n && s[i] == ' ') {
            i++;
        }

        int sign = 1;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        long long num = 0;
        long long limit = (sign == 1) ? INT_MAX : 2147483648LL;

        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            if (num > (limit - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            i++;
        }

        return (int)(sign * num);
    }
};
