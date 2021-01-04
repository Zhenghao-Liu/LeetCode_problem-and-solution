func canPlaceFlowers(flowerbed []int, n int) bool {
    size:=len(flowerbed)
    for i:=0;i<size; {
        if flowerbed[i]==0 {
            j:=i
            for ;j<size;j++ {
                if flowerbed[j]==1 {
                    break
                }
            }
            cnt:=j-i
            if i==0{
                cnt++
            }
            if j==size {
                cnt++
            }
            n-=(cnt-1)/2
            i=j+1
        } else {
            i++
        }
        if n<=0 {
            return true
        }
    }
    return false
}
