s = input().split()
num = int(s[0])
x = int(s[1])
res = 0
i = 1
while (i<num+1):
    str_i = str(i)
    str_x = str(x)
    if str_x in str_i:
        temp = str_i.count(str_x)
        res += temp
    i += 1
print(res)