need = int(input())
n = 0
min_money = 2100000000
while (n<3):
    num, money = map(int,input().split())
    x = need%num
    temp = need//num
    if x==0:
        temp = temp*money
    else:
        temp = (temp+1)*money
    if temp<min_money:
        min_money = temp
    n+=1
print(min_money)