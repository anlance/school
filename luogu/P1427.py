s = input().split()
s_len = int(len(s))
for index in range(s_len):
    if index == 0:
        continue
    print(s[s_len-index-1], end=' ')