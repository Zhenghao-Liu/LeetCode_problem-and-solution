func peakIndexInMountainArray(arr []int) int {
    sz:=len(arr)
    l,r:=1,sz-2
    for l<r {
        mid:=l+(r-l+1)/2
        if arr[mid]>arr[mid-1] {
            l=mid
        } else {
            r=mid-1
        }
    }
    return l
}