isim = "coder"
sehir = "Ankara"
ulke = "Türkiye"

#Klasik metot
print("My Name: ",isim)


#format metodu
print("my name: {}". format(isim))

print("{}, {}'nin başkentidir.". format(sehir,ulke))

print("{0}, {1}'nin başkentidir.". format(sehir,ulke))

print("{1}, {0}'nin başkentidir.". format(ulke,sehir))

print("{s}, {u}'nin başkentidir.". format(u=ulke, s=sehir))

#f string metodu
print(f"my name: {isim}")

print(f"{sehir}, {ulke}'nin başkentidir.")