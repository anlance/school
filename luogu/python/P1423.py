s = float(input())
n = 1
start = 2.0
temp = 2.0
while (temp<s):
    start*=0.98
    temp+=start
    n+=1
print(n)