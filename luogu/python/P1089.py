n = 0
m = 0
hand = 0
mother = 0
m_index = 0
judge = 0
while (n<12):
    m = int(input())
    if m<=(300+hand):
        temp = (300-m) + hand
        while (temp>=100):
            temp -= 100
            mother += 100
        hand = temp
    else:
        judge+=1
        if judge==1:
            m_index = (n+1)
    n+=1
if judge != 0:
    m_index = -m_index
    print(m_index)
else:
    print(int(mother*(1.2))+hand)