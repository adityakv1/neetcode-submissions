class Solution {
public:
    string decodeString(string s) {
        stack<int> stNum;
        stack<string> stStr;

        string curr = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '[') {
                stNum.push(num);
                stStr.push(curr);
                num = 0;
                curr = "";
            }
            else if (c == ']') {
                int repeat = stNum.top(); stNum.pop();
                string temp = curr;
                curr = stStr.top(); stStr.pop();

                while (repeat--) {
                    curr += temp;
                }
            }
            else {
                curr += c;
            }
        }

        return curr;
    }
};