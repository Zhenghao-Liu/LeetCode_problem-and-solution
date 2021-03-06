func isMonotonic(A []int) bool {
    flag1,flag2:=true,true
    sz:=len(A)
    for i:=1;i<sz;i++ {
        if flag1 && A[i]>A[i-1] {
            flag1=false
        }
        if flag2 && A[i]<A[i-1] {
            flag2=false
        }
        if !flag1 && !flag2 {
            return false
        }
    }
    return flag1 || flag2
}
