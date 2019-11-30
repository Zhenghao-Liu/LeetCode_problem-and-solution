```
int min=*min_element(nums.begin(),nums.end()),max=*max_element(nums.begin(),nums.end());

//当公式去记，gap表示桶内间隔
int gap=ceil((max-min)/1.0/(nums_size-1));

//因为有可能出现全为一样数字的情况，这样gap为0，且bucket_size以0为除数会有问题
if (gap==0)
    return 0;
    
//当公式去记，bucket_size表有多少个桶，注意也要向上取整
int bucket_size=ceil((max-min)/1.0/gap);
```
分好各个桶后，对每个桶进行快排(归并、选择之类都行)，最后再连起来
