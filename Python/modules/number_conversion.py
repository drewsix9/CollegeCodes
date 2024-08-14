def deci_to_bin(n):
    power, res = 1, 0
    while n > 0:
        res += (n % 2) * power
        n //= 2
        power *= 10
    return res


def deci_to_octal(n):
    power, res = 1, 0
    while n > 0:
        res += (n % 8) * power
        n //= 8
        power *= 10
    return res


def deci_to_hex(n):
    hexa = '0123456789ABCDEF'
    res = ''
    while n > 0:
        temp = n % 16
        res += hexa[temp]
        n //= 16
    return res[::-1]


def bin_to_deci(n):
    power, res, = 1, 0
    while n > 0:
        res += (n % 10) * power
        n //= 10
        power *= 2
    return res


def octal_to_deci(n):
    power, res = 1, 0
    while n > 0:
        res += (n % 10) * power
        n //= 10
        power *= 8
    return res


def hex_to_deci(n):
    hexa = '0123456789ABCDEF'
    power, res = 1, 0
    for char in n[::-1]:
        res += hexa.index(char) * power
        power *= 16
    return res
