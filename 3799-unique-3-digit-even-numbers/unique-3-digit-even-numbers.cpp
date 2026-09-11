class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> s;

        int n = digits.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {

                    // Cannot use the same array element twice
                    if (i == j || j == k || i == k)
                        continue;

                    // First digit cannot be 0
                    if (digits[i] == 0)
                        continue;

                    // Last digit must be even
                    if (digits[k] % 2 != 0)
                        continue;

                    int num = digits[i] * 100 +
                              digits[j] * 10 +
                              digits[k];

                    s.insert(num);
                }
            }
        }

        return s.size();
    }
};