import modules.number_conversion as nc


def main():
  while True:
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
              print(f'Binary: {nc.deci_to_bin(n)}')
          case 2:
              n = int(input('Enter a binary number: '))
              print(f'Decimal: {nc.bin_to_deci(n)}')
          case 3:
              n = int(input('Enter a decimal number: '))
              print(f'Octal: {nc.deci_to_octal(n)}')
          case 4:
              n = int(input('Enter a octal number: '))
              print(f'Decimal: {nc.octal_to_deci(n)}')
          case 5:
              n = int(input('Enter a decimal number: '))
              print(f'Hexadecimal: {nc.deci_to_hex(n)}')
          case 6:
              n = input('Enter a hexadecimal number: ')
              print(f'Decimal: {nc.hex_to_deci(n)}')
          case 0:
              print('Exiting...')
              return
          case _:
              print('Invalid choice')

main()
