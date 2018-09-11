from collections import Counter

num = "123456789"

for a in num:
    for b in num:
        if b==a:
            continue
        for c in num:
            if c==b:
                continue
            judge = True
            num_s = a+b+c
            num_i = int(num_s)
            num2 = num_i*2
            if num2>999:
                continue
            num2_str = str(num2)
            count_num = Counter(num2_str)
            if count_num.most_common(1)[0][1] > 1:
                continue
            if (a in num2_str) | (b in num2_str) | (c in num2_str) | ('0' in num2_str):
                continue
            else:
                num3 = num_i*3
                if num3>999:
                    continue
                num3_str= str(num3)
                count_num = Counter(num3_str)
                if count_num.most_common(1)[0][1] > 1:
                    continue
                if (a in num3_str) | (b in num3_str) | (c in num3_str) | ('0' in num3_str):
                    continue
                for x in num2_str:
                    if x in num3_str:
                        judge = False
                        break
                if judge == True:
                    print(num_s+' '+num2_str+' '+num3_str)
