# map: map for döngüsü gibi her bir ögeye işlem yapmaya yarar
# map(fonksiyon , liste)

def karesini_al(x):
    return x**2

sayilar = [*range(1,6)]
"""for index in range(len(sayilar)):
    sayilar[index] = karesini_al(sayilar[index])
print(sayilar)"""  # bu 3 satırı map ile 1'e indirgedik

print([*map(karesini_al , sayilar)])
print([*filter(karesini_al , sayilar)])

# filter: bir listedeki verilerin filtrelenmesine yarar(True False kontrolü yapıyor)
# filter(fonksiyon , liste)

def cift_sayilari_filtrele(x):
    if x%2==0:
        return x
    #else:              # else kısmı olsa da olmasa da olur 
    #    return None
    
def cift_sayilari_filtrele(x):
    return x if x%2==0 else None  # ama buradaki else olmazsa olmaz

print([*map(cift_sayilari_filtrele , sayilar)])
print([*filter(cift_sayilari_filtrele , sayilar)])

# lambda: kod yazarken pratik bir şekilde fonksiyon atamaya yarar

print([*map(lambda x: x**2 , sayilar)]) # karesini_al fonksiyonu
print([*filter(lambda x: x**2 , sayilar)])

print([*map(lambda x: x if x%2 == 0 else None , sayilar)]) # cift_sayilari_filtrele fonksiyonu
print([*filter(lambda x: x if x%2 == 0 else None , sayilar)])
