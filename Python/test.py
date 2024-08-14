import modules.number_conversion as nc


def main():
    while True:
        print('Number Conversion')
        print('[0] Exit')
        print('[1] Decimal to Binary')
        print('[2] Binary to Decimal')
        print('[3] Decimal to Octal')
        print('[4] Octal to Decimal')
        print('[5] Decimal to Hexadecimal')
        print('[6] Hexadecimal to Decimal')
        choice = int(input('Enter your choice: '))
        match choice:
            case 1:
                n = int(input('Enter a decimal number: '))
                print(f'\nBinary: {nc.deci_to_bin(n)}\n')
            case 2:
                n = int(input('Enter a binary number: '))
                print(f'\nDecimal: {nc.bin_to_deci(n)}\n')
            case 3:
                n = int(input('Enter a decimal number: '))
                print(f'\nOctal: {nc.deci_to_octal(n)}\n')
            case 4:
                n = int(input('Enter a octal number: '))
                print(f'\nDecimal: {nc.octal_to_deci(n)}\n')
            case 5:
                n = int(input('Enter a decimal number: '))
                print(f'\nHexadecimal: {nc.deci_to_hex(n)}\n')
            case 6:
                n = input('Enter a hexadecimal number: ')
                print(f'\nDecimal: {nc.hex_to_deci(n)}\n')
            case 0:
                print('\nExiting...\n')
                return
            case _:
                print('\nInvalid choice\n')


main()
