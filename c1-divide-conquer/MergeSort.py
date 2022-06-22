from math import ceil

# ====================
# Class definition
# ====================

class Sort:
    """Sorting algorithms: 
    1. MergeSort
    2. TBD
    """

    def mergeSort(str):
        n = len(str)
        if n > 1:
            hidx = ceil(n/2.)

            str1 = str[:hidx]
            str2 = str[hidx:]

            str1 = Sort.mergeSort(str1)
            str2 = Sort.mergeSort(str2)

            i1 = 0
            i2 = 0
            new_str = []
            for i in range(n):
                if str1[i1] < str2[i2]:
                    new_str.append(str1[i1])
                    i1 += 1
                    if i1 == hidx:
                        new_str = new_str + str2[i2:]
                        return new_str
                        
                else:
                    new_str.append(str2[i2])
                    i2 += 1
                    if i2 == (n - hidx):
                        new_str = new_str + str1[i1:]
                        return new_str
        else:
            return str

# ====================
# Main
# ====================

str = [4213, 2312, 1321, 3312, 312, 3414, 42341, 44 , 41 , 42, 31, 123, 12, 50, 1, 2, 33, 45]
str1 = [5, 4, 3, 2, 10, 11, 12, 13] 

print(Sort.__doc__)
print(Sort.mergeSort(str))
