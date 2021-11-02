import math

# xy四角形の中に2つの四角形が入るか
def solve2(x, y, a, b):
    ay = math.ceil(a/x)
    by = y - ay
    return x * by >= b

# xy四角形の中に3つの四角形が入るか
def solve3(x, y, a, b, c):
    ay = math.ceil(a/x)
    if ay >= y:
        return False
    return solve2(x, y - ay, b, c) or solve2(y - ay, x, b, c) 



def main():
    x, y, a, b, c = map(int, input().split())
    
    ok = False
    ok |= solve3(x, y, a, b, c)
    ok |= solve3(x, y, b, c, a)
    ok |= solve3(x, y, c, a, b)
    ok |= solve3(y, x, a, b, c)
    ok |= solve3(y, x, b, c, a)
    ok |= solve3(y, x, c, a, b)

    print("Yes" if ok else "No")

if __name__ == '__main__':
    main()