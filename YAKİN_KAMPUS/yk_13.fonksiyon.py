# return

def bes():
    return 5  # return sadece değer atar yazdırmaz

print(bes())  #Çıktı: 5


def bes():
    return 5

a = bes()
print(a)  #Çıktı: 5

# fonksiyonlarda argümanlar

def sayi(sayi):
    print(sayi)
    
sayi(10)  #Çıktı: 10

# fonksiyonlara default argüman verilebilir

def sayi1(sayi1 = 15):
    print(sayi1)
    
sayi1(10)  #Çıktı: 10
sayi1()  #Çıktı: 15

# birden fazla argüman verilebilir

def buyuk_sayi_dondur(a,b):
    if a>b:
        return a      #returnden sonraki kodlar çalışmaz
    else:
        return b
    
print(buyuk_sayi_dondur(2,3))  #Çıktı: 3

# fonksiyonlari birbirinin icinde cagirabiliriz

def buyugu_yazdir(a,b):
    buyuk_sayi = buyuk_sayi_dondur(a,b)
    print(buyuk_sayi)
    
buyugu_yazdir(3,4)  # Çıktı: 4


def isim_soyisim_ayirma(isim_soyisim):
    isim = isim_soyisim.split()[0:-1]
    soyisim = isim_soyisim.split()[-1]
    return isim , soyisim

print(isim_soyisim_ayirma("Fevzi Sühan Şahin"))
isim , soyisim = isim_soyisim_ayirma("Fevzi Sühan Şahin")
print(isim)
print(soyisim)

# *args: veri sınırlandırmadan bazen 2 bazen 3 ve daha fazla argümanla işlem yapılabilir

def isim_soyisim_birlestirme(isim , soyisim):
    return " ".join([isim , soyisim])  # joinin içinde liste tarzı bir şey olmalı

print(isim_soyisim_birlestirme("Fevzi" , "Sühan"))
# burada iki isimli isim soyisim için sorun çıkıyor ve *args kullanarak çözüyoz

def isim_soyisim_birlestirme(*args):  # args liste gibidir
    return " ".join(args)

print(isim_soyisim_birlestirme("Fevzi" , "Sühan" , "Şahin"))

# **kwargs(çok anlamadım)

def isim_soyisim_yazdir(**kwargs):  # kwargs da dict gibidir
    for kw in kwargs:
        print(kw)
        
isim_soyisim_yazdir(ad='Erol',göbekad='Mesut',soyad='Gün')


def gobek_adi_yazdir(**kwargs):
    if 'göbekad' in kwargs:
        print(kwargs['göbekad'])
    else:
        print('Göbek adi yok')
        
gobek_adi_yazdir(göbekad='Mesut')
gobek_adi_yazdir(ad='Erol')