capcity,fill=map(int,input().split())
if fill > capcity:
	print(capcity)
	exit()
last=0
num=capcity-fill
l,r = 1,num
while(l<=r):
	mid = l + (r-l)//2
	x=(mid*(mid+1))//2
	if(x>=num):
		last = mid
		r = mid - 1
	else:
		l = mid + 1
print(last+fill)
