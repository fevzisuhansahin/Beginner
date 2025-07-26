class Ogrenci:
    def __init__(self, ad,soyad, numara, sinav_not):
        self.ad = ad
        self.soyad = soyad
        self.numara = numara
        self.not_degeri = float(sinav_not)

ogrenciler = []

def ogrenci_ekle():
    numara = input("Ogrenci Numarası : ")
    ad = input("Adı : ")
    soyad = input("Soyad : ")
    not_degeri = input("Not : ")
    ogrenciler.append(Ogrenci(ad, soyad, numara, not_degeri))

def bilgi_goster():
    numara = input("Ogrenci Numarası : ")
    for ogrenci in ogrenciler:
        if ogrenci.numara == numara:
            print(f"Adı : {ogrenci.ad}")
            print(f"Soyad : {ogrenci.soyad}")
            print(f"Numara : {ogrenci.numara}")
            print(f"Not Deger, : {ogrenci.not_degeri}")
            return


def sinif_ort_hesapla():
    notlar = []
    for ogrenci in ogrenciler:
        notlar.append(ogrenci.not_degeri)
    ortalama = sum(notlar) / len(notlar)
    print("\n---Sınıf Ortalaması---")
    print(f"Sınıf Ortalaması : {ortalama:.2f}")

def menu():
    while True:
        print("\n---Ogrenci Sistem---")
        print("1. Ogrenci Ekleme")
        print("2. Bilgi Gosterme")
        print("3. Sınıf Ortalaması Hesaplama")
        print("4. Cikis")
        secim = input("Seciminiz : ")

        if secim == "1":
            ogrenci_ekle()
        elif secim == "2":
            bilgi_goster()
        elif secim == "3":
            sinif_ort_hesapla()
        elif secim == "4":
            print("Cikis Yapildi ")
            break
        else:
            print("Gecersiz secim")


if __name__ == "__main__" :
    menu()


