class Solution {
public:
    int countCommas(int n) {
        int result = 0;

        if (n >= 1000)
            result += n - 1000 + 1;

        if (n >= 1000000)
            result += n - 1000000 + 1;

        if (n >= 1000000000)
            result += n - 1000000000LL + 1;

        return result;
    }
};