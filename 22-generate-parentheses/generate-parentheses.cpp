class Solution {
public:
    vector<string> s;

    vector<string> generateParenthesis(int n) {
        vector<string> s1;

        generate("", n);

        for (int j = 0; j < s.size(); j++) {
            int balance = 0;
            string a = s[j];
            bool valid = true;

            for (int i = 0; i < a.length(); i++) {
                if (a[i] == '(') {
                    balance++;
                }
                else {
                    balance--;

                    if (balance < 0) {
                        valid = false;
                        break;
                    }
                }
            }

            if (valid && balance == 0) {
                s1.push_back(a);
            }
        }

        return s1;
    }

    void generate(string m, int n) {
        if (m.length() == 2 * n) {
            s.push_back(m);
            return;
        }

        generate(m + '(', n);
        generate(m + ')', n);
    }
};