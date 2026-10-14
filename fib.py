import sys

def fib(n):
    a, b = 0, 1
    for _ in range(n):
        yield a
        a, b = b, a + b

if __name__ == "__main__":
    try:
        n = int(sys.argv[1]) if len(sys.argv) > 1 else 20
    except ValueError:
        sys.exit("Ошибка: N должно быть целым числом")
    if n < 0:
        sys.exit("Ошибка: N не может быть отрицательным")
    print(f"Первые {n} чисел Фибоначчи:")
    print(", ".join(str(x) for x in fib(n)))
