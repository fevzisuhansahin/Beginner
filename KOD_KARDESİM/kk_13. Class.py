class Deneme :  # Deneme adında bir class tanımladık
    print("meee")
    
Deneme()

# NESNE TANIMLAMA

class Ogrenci:
    adi = "Ahmet"
    soyadi = "Demir"
    sinifi = "8"
    
print(Ogrenci.adi,Ogrenci.soyadi,Ogrenci.sinifi)
print(Ogrenci.soyadi)
print(Ogrenci.sinifi)

# BİRDEN FAZLA NESNE İÇİN

class Karakter:
    adi = ""
    gucu = ""
    rutbesi = ""
    yeteneği = []
    
sage = Karakter()   # 1. karakteri oluşturduk
sage.adi = "Sage"
sage.gucu = 500
sage.rutbesi = "çaylak"
sage.yeteneği += ["Diriltme"]

print(f"{sage.adi} {sage.gucu} {sage.rutbesi} {sage.yeteneği}")

raze = Karakter()
raze.adi = "Raze"
raze.gucu = 1000
raze.rutbesi = "uzman"
raze.yeteneği += ["Roketatar"]

print(f"{raze.adi} {raze.gucu} {raze.rutbesi} {raze.yeteneği}")

#    Burada 2 sıkıntı var:
# 1. class kullanacağımız zaman böyle bir sürü kod mu yazacaz
# 2. raze'in yeteneğinde 'Diriltme' de var

class Talebe():
    def __init__(self , ad , soyad , sinif):
        print(f"{ad} {soyad} {sinif}")
        
Talebe("Ahmet" , "Duran" , 12)

class Talebe():
    def __init__(self , ad , soyad , sinif):
        self.adi = ad
        self.soyadı = soyad
        self.sinifi = sinif
        
mehmet = Talebe("Mehmet" , "Kal" , 12)

print(f"""Adı: {mehmet.adi}
Soyadı: {mehmet.soyadı}
Sınıfı: {mehmet.sinifi}""")