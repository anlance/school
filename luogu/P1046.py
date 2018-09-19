s = input().split()
high = int(input())+30
num = 0
for item in s:
    if int(item) <= high:
        num+=1
print(num) 