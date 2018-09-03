s = input().split()
ans_h = 0
ans_m = 0
if int(s[3]) < int(s[1]):
    ans_m = int(s[3])+60-int(s[1])
    ans_h = int(s[2])-1-int(s[0])
else:
    ans_m = int(s[3])-int(s[1])
    ans_h = int(s[2])-int(s[0])
print(str(ans_h)+' '+str(ans_m))