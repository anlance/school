s = input().split()
day = int(s[0])
n =  int(s[1])
res = 0
if n+day<7:
    if n+day>5:
        res=(5-day+1)*250
    else:
        res = n*250
else:
    temp = 7 - day + 1
    if temp>2:
        res = (temp-2)%6*250
    else:
        res = 0
    day = n - temp
    num = day//7
    last_day = day%7
    if last_day>5:
        last_day=5
    res += (num*5+last_day)*250
print(res)
