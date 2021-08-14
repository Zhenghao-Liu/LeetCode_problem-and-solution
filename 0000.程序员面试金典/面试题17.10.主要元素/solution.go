func majorityElement(nums []int) int {
    cur,cnt:=0,0
    for _,i:=range nums {
        if cnt==0 {
            cur=i
            cnt=1
            continue
        }
        if i==cur {
            cnt++
        } else {
            cnt--
        }
    }
    if cnt==0 {
        return -1
    }
    cnt=0
    for _,i:=range nums {
        if i==cur {
            cnt++
        }
    }
    if cnt>len(nums)/2 {
        return cur
    }
    return -1
}