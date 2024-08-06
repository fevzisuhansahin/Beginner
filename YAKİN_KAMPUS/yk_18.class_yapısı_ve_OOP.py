# CLASS YAPISI
"""class <Class Ismi>(): ## class isimleri, genelin aksine büyük harfle baslar (zorunluluk degil)
    
    <class attr>   ## class attribute, olusturulanin aksine genel degerleri icerir
    
    def __init__(self, <attr>):       ## init, instantiation yani örneklendirmenin kisaltmasidir
        self.<instance attr> = attr   ## instance attribute'lar, olusturulan örnege özgüdür
        ...
    
    def <method>(self, <params>):     ## methodlar class'a özgü fonksiyonlardir
        ...
        return ..."""
        
class Ucus(): # class'a "Ucus" diye isim verdim
    havayolu = "THY" # class'a attribte(özellik) tanımladım. Her öge için aynıdır değişmez
    
ucus = Ucus() # class'a bir öge ekledim

print(ucus.havayolu) # her ögenin genel özelliği olan havayolunu yazdırdım



class Ucus1():
    havayolu = "THY"
    
    def __init__(self, kod, kalkis, varis, sure, kapasite, yolcu):
        self.kod = kod              # yukarıdakı self ögeyi refere eder
        self.kalkis = kalkis        # selfin yanındakiler ögelerin özel özellikleri
        self.varis = varis          # class'a öge tanımlarken self hariç özellikleri de yazmak zorundayız
        self.sure = sure            
        self.kakapasite =kapasite
        self.yolcu = yolcu
        
ucus1 = Ucus1(123, "IST", "ANK", 60, 250, 150) # bir öge ekledim özellikleriyle
ucus11 = Ucus1(111, "IST", "ANT", 45, 300, 50) # bir tane daha ekledim

print(ucus1.kalkis)
print(ucus1.havayolu)
print(ucus11.varis)
print(ucus11.havayolu)



class Ucus2():
    havayolu = "THY"
    
    def __init__(self, kod, kalkis, varis, sure, kapasite, yolcu):
        self.kod = kod
        self.kalkis = kalkis
        self.varis = varis
        self.sure = sure
        self.kapasite = kapasite
        self.yolcu = yolcu
        
    def anons(self):
        return f"{self.kod} kodlu {self.kalkis}-{self.varis} seferimiz {self.sure} dakika sürecektir"
    
    def bos_koltuk_sayısı(self):
        return f"Boş koltuk sayısı: {self.kapasite - self.yolcu}"
    
    def bilet_satis(self):
        bilet_sayisi = int(input("Kaç adet bilet almak istiyorsunuz: "))
        if bilet_sayisi <= (self.kapasite - self.yolcu):
            self.yolcu += bilet_sayisi
            print(f"{bilet_sayisi} adet bilet satıldı. Kalan boş koltuk: {self.kapasite - self.yolcu}")
        else:
            print("Yetersiz boş koltuk. İşlem gerçekleştirilemedi.")
            
    def bilet_iptali(self):
        bilet_sayisi = int(input("İptal etmek istediğiniz adedi girin: "))
        if bilet_sayisi <= self.yolcu:
            self.yolcu -= bilet_sayisi
            print(f"{bilet_sayisi} adet bilet iptal edildi. Kalan boş koltuk : {self.kapasite - self.yolcu}")
        else:
            print("İptal edilecek kadar bilet yok. İşlem gerçekleştirilemedi.")
            
ucus2 = Ucus2(123, "IST", "ANK", 60, 250, 150)
ucus21 = Ucus2(111, "IST", "ANT", 45, 300, 50)

print(ucus2.anons())
print(ucus21.bos_koltuk_sayısı())
ucus2.bilet_satis()
ucus21.bilet_iptali()
ucus2.bilet_satis()