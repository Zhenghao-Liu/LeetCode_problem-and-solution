class Solution {
public:
    string maximumTime(string time) {
        if (time.at(0)=='?') {
            if (time.at(1)=='?' || time.at(1)<='3') {
                time.at(0)='2';
            } else {
                time.at(0)='1';
            }
        }
        if (time.at(1)=='?') {
            time.at(1)= time.at(0)=='2' ? '3' : '9';
        }
        time.at(3)= time.at(3)=='?' ? '5' : time.at(3);
        time.at(4)= time.at(4)=='?' ? '9' : time.at(4);
        return time;
    }
};
