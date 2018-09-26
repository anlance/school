num = int(input())
s = input().split()
fish_num = [0]*num
fish_num[0] = 0
i = 1
while i<num:
    for index in range(len(s)):
        if index < i:
            if int(s[index]) < int(s[i]):
                fish_num[i] += 1
    i += 1

for item in fish_num:
    print(item,end=" ") 