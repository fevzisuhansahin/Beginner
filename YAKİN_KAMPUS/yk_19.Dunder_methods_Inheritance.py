# DUNDER(Double Under Score) Metodları

class Ucus():
    havayolu = "THY"
    
    def __init__(self, kod, kalkis, varis, sure, kapasite, yolcu):
        self.kod = kod
        self.kalkis = kalkis
        self.varis = varis
        self.sure = sure
        self.kapasite = kapasite
        self.yolcu = yolcu
        
    def __repr__(self):
        print(f"{self.kod} nolu uçuş sisteme kaydedildi")
        
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
            
ucus = Ucus(123, "IST", "ANK", 60, 250, 150)

print(ucus.__dir__()) # __dir__ kullanarak o ögede hangi fonksiyonları çalıştırabileceğimizi görürüz

# __repr__ : ögeyi fonksiyonsuz yazdırınca o ögenin hafızadaki yerini bastırır. Bunu engellemek için kullanılır

# print(ucus) #  eğer __repr__ kullanmazsak bunun çıktısı: <__main__.Ucus object at 0x00000211E5663290>
ucus.__repr__()


# INHARITANCE(Kalıtım): class'ları birbiri içinde kullanma(alt üst class muhabbeti)

class Seyahat(): # üst class'ı tanımladım
    
    def __init__(self, kalkis, varis): # hem bu class'ı hem de alt class'ları etkileyecek özellikler
        self.kalkis = kalkis
        self.varis = varis
        
    def anons(self):
        print(f"{self.kalkis}-{self.varis} seferine hoşgeldiniz...")
    
class Otobus(Seyahat): # parantez içine üst class'ı yazıyoz
    
    def __init__(self, mola_yerleri, kalkis, varis):
        super().__init__(kalkis, varis) # bu satır üst fonksiyondaki özellikleri kullanmamız için var
      # Seyahat().__init__(kalkis, varis) bu şekilde de yazılabilir
        self.mola_yerleri = mola_yerleri # bu satır sadece Otobüs class'ı için geçerli

seyahat = Seyahat("İstanbul", "Niğde")
otobus = Otobus(["Düzce", "Ankara"], "İstanbul", "Niğde")

otobus.anons()
print(otobus.mola_yerleri)