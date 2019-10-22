class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int digits_size=digits.size(),carry=0;
        if (digits.at(digits_size-1)<9)
        {
            digits.at(digits_size-1)=digits.at(digits_size-1)+1;
            return digits;
        }
        else
        {
            carry=1;
            digits.at(digits_size-1)=0;
        }
        for (int i=digits_size-2;i>=0;i--)
        {
            if (carry==1)
                if (digits.at(i)<9)
                {
                    digits.at(i)=digits.at(i)+1;
                    carry=0;
                }
                else
                {
                    digits.at(i)=0;
                    carry=1;
                }
            else
                break;
        }
        if (carry==1)
            digits.insert(digits.begin(),1);
        return digits;
    }
};
