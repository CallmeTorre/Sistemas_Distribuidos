import random
import string

def genString():
    return "".join(random.choice(string.ascii_uppercase) for _ in range(3))

def main():
    test = genString()
    for _ in range(100000000):
        test += " " + genString()
    print(test.count("IPN"))

if __name__ == "__main__":
    main()