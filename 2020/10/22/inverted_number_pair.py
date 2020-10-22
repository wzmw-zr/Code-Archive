def merge(nums : list, left : int, right : int) -> int : 
    if (left >= right) :
        return 0
    cnt = 0
    mid = (left + right) // 2
    x = left
    y = mid + 1
    data = []
    while (x <= mid or y <= right) : 
        if (x <= mid and (y > right or nums[x] < nums[y])) : 
            data.append(nums[x])
            x += 1
        else : 
            data.append(nums[y])
            y += 1
            cnt += mid + 1 - x
    for i in range(0, right - left + 1) : 
        nums[i + left] = data[i]
    return cnt

def merge_sort(nums : list, left : int, right : int) -> int : 
    if (left >= right) :
        return 0
    mid = (left + right) // 2
    cnt = 0
    cnt += merge_sort(nums, left, mid)
    cnt += merge_sort(nums, mid + 1, right)
    cnt += merge(nums, left, right)
    return cnt

def inverted_number_pair(nums : list) -> int : 
    return merge_sort(nums, 0, len(nums) - 1)

a = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
print(inverted_number_pair(a))