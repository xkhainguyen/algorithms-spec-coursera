from math import ceil
# ====================
# Class definition
# ====================

class CountInv:
    """Counting Iversions: 
    Use Merge Sort
    """
    def merge_and_countSplitInv(B, C):
        i1 = 0
        i2 = 0
        D = []
        n = len(B) + len(C)
        Z = 0
        for i in range(n):
            if B[i1] < C[i2]:
                D.append(B[i1])
                i1 += 1
                if i1 == len(B):
                    D = D + C[i2:]
                    return D, Z
                    
            else:
                D.append(C[i2])
                i2 += 1
                Z += len(B) - i1
                if i2 == len(C):
                    D = D + B[i1:]
                    return D, Z

    def sort_and_count(A):
        n = len(A)
        if n > 1:
            hidx = ceil(n/2.)

            B, X = CountInv.sort_and_count(A[:hidx])
            C, Y = CountInv.sort_and_count(A[hidx:])
            D, Z = CountInv.merge_and_countSplitInv(B, C)

            return D, (X + Y + Z)
            
        else:
            return A, 0

# ====================
# Main
# ====================

# A = [4, 80, 70, 23, 9, 60, 68, 27, 66, 78, 12, 40, 52, 53, 44, 8, 49, 28, 18, 46, 21, 39, 51, 7, 87, 99, 69, 62, 84, 6, 79, 67, 14, 98, 83, 0, 96, 5, 82, 10, 26, 48, 3, 2, 15, 92, 11, 55, 63, 97, 43, 45, 81, 42, 95, 20, 25, 74, 24, 72, 91, 35, 86, 19, 75, 58, 71, 47, 76, 59, 64, 93, 17, 50, 56, 94, 90, 89, 32, 37, 34, 65, 1, 73, 41, 36, 57, 77, 30, 22, 13, 29, 38, 16, 88, 61, 31, 85, 33, 54]

with open("./c1-divide-conquer/file-test.txt", 'r') as file:
    A = [int(x) for x in file.read().split('\n')]
# print(int('12312312123'))
print(CountInv.__doc__)
print(CountInv.sort_and_count(A)[1])