# Uses python3
import sys

def get_change(m):
    amount = 0
    while(m > 9):
        amount = amount + 1
        m = m -10
    while(m > 4):
        amount = amount + 1
        m = m -5
    while(m != 0):
        amount = amount + 1
        m = m - 1

    #write your code here
    return amount

if __name__ == '__main__':
    m = int(sys.stdin.read())
    print(get_change(m))
