class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int sz=num.size();
        for (int i=0;i<sz;i++) {
            if (num.at(i)<'0'+change.at(num.at(i)-'0')) {
                while (i<sz && num.at(i)<='0'+change.at(num.at(i)-'0')) {
                    num.at(i)='0'+change.at(num.at(i)-'0');
                    i++;
                }
                break;
            }
        }
        return num;
    }
};