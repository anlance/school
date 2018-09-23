# s = input().split()
# max_len = int(s[0])
# num = int(s[1])
# tree = []
# i = 0
# res = max_len + 1
# while i < num:
#     # print('-------')
#     # for item in tree:
#     #     print(item)
#     # print('-------')
#     i+=1
#     s = input().split()
#     l = int(s[0])
#     h = int(s[1])
#     if i==1:
#         tree.append(l)
#         tree.append(h)
#     else:
#         index = 0
#         tree_len = int(len(tree))
#         while int(index) < tree_len:
#             tree_l = int(tree[index])
#             tree_h = int(tree[index+1])
#             if l <= tree_l:
#                 if h >= tree_h:
#                     tree[index] = l
#                     tree[index+1] = h
#                     break
#                 elif h >= tree_l and h <tree_h:
#                     tree[index] = l
#                     break
#                 elif h < tree_l:
#                     tree.append(l)
#                     tree.append(h)
#                     break
#             elif (l > tree_l) and (l < tree_h):
#                 if h >= tree_h and h <= max_len:
#                     tree[index+1] = h
#                     break
#             elif l >= tree_h and l <= max_len:
#                 tree.append(l)
#                 tree.append(h)
#                 break
#             index+=2
#     flag = False
#     while flag == False:
#         flag = True
#         index = 0
#         while index < int(len(tree)):
#             l  = tree[index]
#             h = tree[index+1]
#             temp = index+2
#             while temp < int(len(tree)):

s = input().split()
max_len = int(s[0])
num = int(s[1]) 
tree = [0]*(max_len+1)
i = 0
res = max_len+1
while i < num:
    i += 1
    s = input().split()
    l = int(s[0])
    h = int(s[1])
    if l >=0 and h <= max_len:
        temp = l
        while temp <= h:
            tree[temp] = 1
            temp +=1
for item in tree:
    if item == 1:
        res -= 1
print(res)
# # for index in range(len(tree)):
# #     if index%2 == 0:
# #         res -= 1
# #         res += int(tree[index])
# #     else:
# #         res -= int(tree[index])
# #     print('-'+str(res))
# # print(res)