# RANGE = aralık belirtir

print(type(range(2)))
print(range(1,4))
print(list(range(1,4)))
print([*range(1,4)])  # bu yöntemle de list veri tipine dönüştürebiliriz
print(set(range(1,4)))
print(tuple(range(1,4)))

for i in range(1,4):
    print(i)
    
# ENUMERATE = liste içindeki ögelerin indexini verir

harfler = ["a" , "b" , "c"]
for i in enumerate(harfler):
    print(i)

harfler = ["a" , "b" , "c"]
for i,j in enumerate(harfler):
    print(i)
    
harfler = ["a" , "b" , "c"]
for i,j in enumerate(harfler):
    print(j)
    
# ZİP = listeleri birleştirmeye yarar

adlar = ["amet" , "memet" , "fevzi"]
soyadlar = ["falan" , "gurbuz" , "sahin"]
yaslar = (1 , 2 , 3)

for info in zip(adlar,soyadlar,yaslar):
    print(info)