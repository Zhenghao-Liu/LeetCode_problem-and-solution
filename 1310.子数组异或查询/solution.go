func xorQueries(arr []int, queries [][]int) []int {
    szA,szQ:=len(arr),len(queries)
    vec:=make([]int,szA+1)
    for i:=0;i<szA;i++ {
        vec[i+1]=vec[i]^arr[i]
    }
    ans:=make([]int,szQ)
    for i:=0;i<szQ;i++ {
        a,b:=queries[i][0],queries[i][1]
        ans[i]=vec[a]^vec[b+1]
    }
    return ans
}