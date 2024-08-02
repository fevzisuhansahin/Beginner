# [a , b , c , d , e , f ]
#  0 | 1 | 2 | 3 | 4 | 5  
#  0 |-6 |-5 |-4 |-3 |-2 

liste = ["a" , "b" , "c" , "d" , "e" , "f"]

# listeye veri ekleme
liste = liste + ["a"] 
liste.append("b")
print(liste)

#listeden veri çıkarma
liste.pop(6) # 6 indexli veriyi çıkar
print(liste)

print(liste[::2])
print(liste[2:7])

liste2 = ["ahmet" , "bel" , "tank" , "c" , "de"]
liste2.sort()
print(liste2)

sayi = [1,11,2]
print(sayi.sort()) # bu kullanımda sort fonksiyonu işini yapar ama bize veri return etmez. bu yüzden 'None' çıktısı alırız

sayilar = [24 ,5779 , 651 , 1 , 1]
sayilar.sort() # verileri küçükten büyüğe sıralar ve tekrar edenleri de tekrar ettirir
print(sayilar)

sayilar.reverse() # verileri reverse etti
print(sayilar)

# list türündeki bir listedeki tekrar eden değerleri silme

"""dizi = [1,3,5,8,11,"a", "a" , "s21sdF", 1 , 8 , 3 , 54 , 88, 13 ,2, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1, "1", 5 , 8, "a"] # 13

def clean(arr):
    for i in range(len(arr)):
        for j in range(i+1,len(arr)):
            if j >= len(dizi):
                break
            if dizi[i] == dizi[j]:
                print("Aynı değer yakalandı!")
                print(f"i nin indexi = {i} ve değeri = {dizi[i]}.")
                print(f"j nin indexi = {j} ve değeri = {dizi[j]}.")
                dizi.pop(i)
                clean(dizi)
        if i >= len(dizi):
                break

clean(dizi)
"""