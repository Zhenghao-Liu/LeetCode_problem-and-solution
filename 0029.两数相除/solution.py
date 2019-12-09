class Solution(object):
    def divide(self, dividend, divisor):
        if (dividend==0):
            return 0
        elif (dividend==divisor):
            return 1
        INT_MAX=2147483647
        INT_MIN=-2147483648
        sign=0
        if ( dividend^divisor>0 ):
            sign=1
        else:
            sign=-1
        dividend=abs(dividend);
        divisor=abs(divisor);
        if (divisor==1):
            if (sign*dividend>INT_MAX or sign*dividend<INT_MIN):
                return INT_MAX
            else:
                return sign*dividend
        quotient=0
        i=0
        divisor_original=divisor
        while (dividend>=divisor):
            dividend=dividend-divisor
            i=i+1
            quotient=quotient+i
            divisor=divisor+divisor_original
        while (dividend>=divisor_original):
            dividend=dividend-divisor_original
            quotient=quotient+1
        if (quotient>INT_MAX or quotient<INT_MIN):
            return INT_MAX
        else:
            return sign*quotient
