n = int(input("element: "))
arr = [1, 1, 2, 2, 2, 2, 2, 6, 6, 6, 12, 25, 37, 45, 65, 77]

large = len(arr) - 1
small = 0
mid = 0

while small < large:
    mid = (large + small)//2
    if arr[mid] < n:
        small = mid + 1
    elif arr[mid] > n:
        large = mid - 1
    else:
        break

found_index = mid
print(found_index)

# found_index = 3
# 1, 1, 2, 2, 2, 2, 2, 6, 6, 6, 12, 25, 37, 45, 65, 77

large = len(arr)
while found_index < large:
    mid = (found_index + large)//2
    print(mid)
    if arr[mid] < n:
        found_index = mid + 1
    elif arr[mid] > n:
        large = mid - 1
    else:
        found_index = mid
        break

strtindex = mid
print(strtindex)

while found_index > small:
    mid = (found_index + small)//2
    if arr[mid] > n:
        found_index = mid + 1
    elif arr[mid] < n:
        small = mid - 1
    else:
        break

endindex = mid
print(endindex)
