T = int(input())


for _ in range(T):
    A = list(map(int, input().split()))
    A.sort()
    if A[0] == A[1]:
        print(A[0])
    elif A[1] == A[2]:
        print(A[1])
    else:
        
        diff1 = (A[1] - A[0])//2
        A[0] += 2*diff1
        A[1] -= diff1
        A[2] -= diff1
        A.sort()

        diff2 = (A[2] - A[1])//2
        A[0] += 2*diff2
        A[1] -= diff2
        A[2] -= diff2
        A.sort()

        if A[0] == A[1]:
            print(A[0] + diff1 + diff2)
        elif A[1] == A[2]:
            print(A[1] + diff1 + diff2)
        else:
            print(-1)
