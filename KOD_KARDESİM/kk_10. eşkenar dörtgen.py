def sag_slas(adet):
    for i in range(int(adet)):
        print("/", end="")

def sol_slas(adet):
    for i in range(int(adet)):
        print("\\", end="")

def satir_atla(adet):
    for i in range(int(adet)):
        print()

def bosluk(adet):
    for i in range(int(adet)):
        print(" ", end="")

def ust(cap):
    bas_bosluk = (cap / 2) - 1
    for i in range(int(cap / 2)):
        bosluk(bas_bosluk - i)
        sag_slas(1)
        bosluk(i * 2)
        sol_slas(1)
        satir_atla(1)

def alt(cap):
    bas_bosluk = cap - 2
    for i in range(int(cap / 2)):
        bosluk(i)
        sol_slas(1)
        bosluk(bas_bosluk - (i * 2))
        sag_slas(1)
        satir_atla(1)

def eskenar_dörtgen(cap):
    ust(cap)
    alt(cap)

while True:
    eskenar_dörtgen(int(input("Çap Girin(çift sayı): ")))