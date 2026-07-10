class Solution {
public:
    bool matcher(string& s, string& p, int i, int j) {
        if (j == p.size()) {
            return i == s.size();
        }

        if (i == s.size()) {
            if (p[j] == '*') {
                return matcher(s, p, i, j + 1);
            }

            if (j + 1 < p.size() && p[j + 1] == '*') {
                return matcher(s, p, i, j + 1);
            }

            return false;
        }

        // Handle x* BEFORE normal matching
        if (j + 1 < p.size() && p[j + 1] == '*') {
            return matcher(s, p, i, j + 1);
        }

        if (s[i] == p[j] || p[j] == '.') {
            return matcher(s, p, i + 1, j + 1);
        }
        else if (p[j] == '*') {
            bool res = false;

            // Stop repeating
            res = res || matcher(s, p, i, j + 1);

            // Take one more
            if (s[i] == p[j - 1] || p[j - 1] == '.') {
                res = res || matcher(s, p, i + 1, j);
            }

            return res;
        }

        return false;
    }

    bool isMatch(string s, string p) {
        return matcher(s, p, 0, 0);
    }
};