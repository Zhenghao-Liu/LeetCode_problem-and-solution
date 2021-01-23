func prefixesDivBy5(A []int) []bool {
    size := len(A)
    ans := make([]bool,size,size)
    var num = 0
    for i,v := range A {
        num <<= 1
        num += v
        num %= 5
        if num == 0 {
            ans[i] = true
        }
    }
    return ans
}
