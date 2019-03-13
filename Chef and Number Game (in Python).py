t = int(input())

while t:
    n = int(input())
    a = list(map(int,input().split()))
    pos = 0
    neg = 0
    for i in range(0,n):
        if a[i] < 0:
            neg += 1
        else:
            pos += 1
            
    if pos == n:
        print(pos,pos)
    elif neg == n:
        print(neg,neg)
    else:
        print(pos,neg)
    t-=1
