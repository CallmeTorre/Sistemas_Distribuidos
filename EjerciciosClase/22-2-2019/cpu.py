import math

MAX = 100000000

def main():
    i, seno, coseno, tangente, logaritmo, raizCuadrada = 1, 1, 1, 1, 1, 1
    while(i < MAX):
        seno += math.sin(i)
        coseno += math.cos(i)
        tangente += math.tan(i)
        logaritmo += math.log(i)
        raizCuadrada += math.sqrt(i)
        i += 1

if __name__ == "__main__":
    main()