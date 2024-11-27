"print(5 + 'a')" # TypeError hatası verir

try:
    5 + "a"
except IndexError: # hata tipi doğru yazılmalı
    print("Bu indexteki veri yok")
except:
    print("bu verilerle işlem yapılamaz")
    

"liste = []"  # IndexError hatası verir
"liste[4]"

liste = []

try:
    liste[2]
except IndexError:
    print("Aradığınız indexte veri yok")
except:
    print("Kod düzgün çalışmıyor")
    

a = {
    "ad" : "fevzi",
    "yas" : 20
}
    
try:
    a["TC no"]
except IndexError:
    print("Aradığınız indexte veri yok")
except KeyError:
    print("Böyle bir key yok")
except:
    print("Kod düzgün çalışmıyor")