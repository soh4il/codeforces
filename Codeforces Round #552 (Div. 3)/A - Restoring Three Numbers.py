arr = list(map(int,input().split()))
arr.sort()
for i in range(3):
    print(arr[-1] - arr[i],end=' ')
print()
