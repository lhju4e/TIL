str1 = "backjoon"
# print(str1)
list1 = [s for s in str1]
alphabet_list = [chr(i) for i in range(97, 97+26)]

for s in alphabet_list:
    if s in list1:
        print(list1.index(s), end=' ')
    else:
        print(-1, end=' ')
