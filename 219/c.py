X= input()
N = int(input())

strs = [input() for _ in range(N)]

normal = [chr(x+97) for x in range(26)]

dic1 = {}
dic2 = {}
for i, s in enumerate(X):
    dic1[s] = normal[i]
    dic2[normal[i]] = s 


conv_strs = []
for str in strs:
    conv_str = ""
    for c in str:
        conv_str += dic1[c]
    conv_strs.append(conv_str)

conv_strs.sort()

for str in conv_strs:
    ans = ""
    for c in str:
        ans += dic2[c]
    print(ans)

