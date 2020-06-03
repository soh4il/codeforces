l = int(input())
n = input()
ans = int(n)
mid = l//2
if n[mid] != '0':
    ans = int(n[:mid])+int(n[mid:])
i = l//2
out = False
for j in range (1,mid+1):
    if i+j<l:
        if(n[i+j] != '0'):
            temp = int(n[:i+j])+int(n[i+j:])
            ans = min(ans,temp)
            out = True
    if i-j>0:
        if(n[i-j] != '0'):
            temp = int(n[:i-j])+int(n[i-j:])
            ans = min(ans,temp)
            break
    if out:
        break

print(ans);
