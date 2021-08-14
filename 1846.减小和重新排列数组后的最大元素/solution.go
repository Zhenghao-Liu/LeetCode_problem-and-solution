func maximumElementAfterDecrementingAndRearranging(arr []int) int {
	sort.Ints(arr)
	arr[0]=1
	sz:=len(arr)
	for i:=1;i<sz;i++ {
		arr[i]=min(arr[i-1]+1,arr[i])
	}
	return arr[sz-1]
}
func min(a,b int) int {
	if a<b {
		return a
	}
	return b
}