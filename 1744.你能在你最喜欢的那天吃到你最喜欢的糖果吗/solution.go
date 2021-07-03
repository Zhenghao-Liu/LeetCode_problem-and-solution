func canEat(candiesCount []int, queries [][]int) []bool {
    sz1,sz2:=len(candiesCount),len(queries)
    pre:=make([]int,sz1+1)
    for i:=range candiesCount {
        pre[i+1]=pre[i]+candiesCount[i]
    }
    ans:=make([]bool,sz2)
    for i:=range queries {
        mi,mx:=(queries[i][1]+1),queries[i][2]*(queries[i][1]+1)
        low,up:=pre[queries[i][0]]+1,pre[queries[i][0]+1]
        if (mi<=low && mx>=up) || (mx<=up && mx>=low) || (mi>=low && mi<=up) {
            ans[i]=true
        } 
    }
    return ans
}