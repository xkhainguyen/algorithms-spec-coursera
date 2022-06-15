from math import ceil
import time

# ====================
# Class definition
# ====================

class Karatsuba:
    """Karatsuba's alogrithm on integer multiplication"""

    def pad_zero(num1, num2):
        str1 = str(num1)
        str2 = str(num2)
        n0 = len(str1) - len(str2)
        while not n0 == 0:
            if n0 > 0:
                str2 = '0' + str2
            if n0 < 0:
                str1 = '0' + str1
            n0 = len(str1) - len(str2)
        return str1, str2

    def mul(num1, num2):
        str1, str2 = Karatsuba.pad_zero(num1, num2)
        n = len(str1)
        if n > 1:
            hdigit = ceil(n/2.) 

            a = str1[:hdigit]
            b = str1[hdigit:]
            c = str2[:hdigit]
            d = str2[hdigit:]

            ac = Karatsuba.mul(int(a), int(c))
            bd = Karatsuba.mul(int(b), int(d))

            a_b = int(a) + int(b)
            c_d = int(c) + int(d)
            sum = Karatsuba.mul(a_b, c_d)
            ad_bc = sum - ac - bd

            res = ac*10**((n - hdigit)*2) + (ad_bc)*10**(n - hdigit) + bd
            # print(res, '==', num1*num2)
            return res
        else:
            return num1*num2

# ====================
# Main
# ====================

num1 = 999998999
num2 = 998999999

# num1 = 9509090958164057267497022913300417684341772484307875629755329462831070821785127159670052473793464100979339895889746353138559887988294355346396259803963956030063880220813053988520717421913782288218444359253148866287554851687427214264758532702784990463166050
# num2 = 8869905480101421754029658022141462145364998772684420847838410201867544038345041673755428184096957803661971239945690101337347013995167200299368957070993663445317591147229634611657120605175033869194756084492011109267497808621959974001499202660852430421078437

print(Karatsuba.__doc__)

start = time.time()
print(Karatsuba.mul(num1, num2))
end = time.time()
print(num1*num2)
end2 = time.time()
print("Running time of Karatsuba: ", end - start, "\nRunning time of default: ", end2 - end)