n = 0
max_d = 8
max_d_index = 0
while (n < 7):
    s, p = map(int,input().split())
    n += 1
    if (s+p)>max_d:
        max_d = s+p
        max_d_index = n

print(max_d_index)