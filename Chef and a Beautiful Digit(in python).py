#input test cases
T = int(input())

while T:
    #input N and d
    N,d = map(str,input().split())
    
    c = 0
    s = []
    
    #find no of digits in N greater than d
    for i in range(0,len(N)):
        if N[i] > d:
            c+=1
        else:
            s.append(N[i])
    
    #reverse the array s and store in rs (reverse of s)        
    rs = []
    for i in range(len(s)-1,-1,-1):
        rs.append(s[i])
    
    #find the minimum no (ans)
    ans = ""
    while len(rs) > 0:
        i = len(rs) - 1
        x = i
        m = rs[i]
        for j in range(i-1,-1,-1):
            if rs[j] < m:
                m = rs[j]
                x = j
        while i > x:
            rs.pop()
            c+=1
            i-=1    
        ans = ans + rs[x]
        rs.pop()
        
    while c > 0:
        ans = ans + d
        c-=1
        
    #output the minimum number
    print(ans)
    T-=1
