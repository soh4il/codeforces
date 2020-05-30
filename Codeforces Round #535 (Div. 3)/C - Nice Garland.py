def recolor(s,per):
    recol=0    
    for i in range(3):
        if(s[i]!=per[i]):
            recol=recol+1
 
    return recol
 
per=["RGB","RBG","GBR","GRB","BRG","BGR"]
 
len_=int(input())
string=input()
old_acc=200005
per_in=0
 
 
for i in range(6):
    accum=0
    n=0
    while(n+3<=len_):
        if(string[n:n+3] != per[i]):
            accum+=recolor(string[n:n+3],per[i])
 
        if(accum>=old_acc):
            break
    
        n=n+3
    for x in range(len_%3):
        if(string[n+x]!=per[i][x]):
            accum+=1
 
 
    if(accum<old_acc):
        per_in=i
        old_acc=accum
 
 
 
out=(len_//3)*per[per_in]+per[per_in][:len_%3]
print(old_acc)
print(out)
