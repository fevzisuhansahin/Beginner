# P | Y | T | H | O | N
# 0 | 1 | 2 | 3 | 4 | 5      # İKİ YÖNTEM DE STRİNG İÇİNDEKİ HER BİR KARAKTERİ SIRALAR
# 0 |-5 |-4 |-3 |-2 |-1

# '[]'   : tek bir eleman alinir
# '[:]'  : baslangic ve bitis arasindaki elemanlar alinir
# '[::]' : baslangic ve bitis arasindaki elemanlar ücüncü kisimdaki degere gore atlayarak degeler alinir
# len() = length(uzunluk)

thing = "Python"

print(thing[1])
print(thing[3:6])  # iki noktanın sağı dahildir ama solu dahil değildir
print(thing[:3])   # iki noktanın boş bıraktığınız yeri en son olarak alınır
print(thing[2:])
print(thing[::2])
print(thing[1::2])
print(thing[1:4:2])
print(len(thing))
print(thing + " verse")
print(thing * 5)
print(thing.upper())
print(thing.lower())

a = "Python ogren Yakin Kampus"

print(a.split())   # split komutunun defaultu " " dur
print(a.split(" "))
print(a.split("n"))
print(a.split("o"))
print(a.split("o", 1)) # splitin içindeki ikinci input max kaç kere ayırma işlemi yapacağını belirtir
print(a.split("k"))