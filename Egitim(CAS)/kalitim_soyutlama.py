class BankaHesabi:
    def __init__(self, kullanici, bakiye, fatura_tarih):
        self.kullanici = kullanici
        self.__bakiye = bakiye
        self.tarih = fatura_tarih

    def get_bakiye(self):
        return self.__bakiye
    
    def set_bakiye(self, yeni_deger):
        if yeni_deger >= 0:
            self.__bakiye = yeni_deger
        else:
            print("Bakiye (-) olamaz")

B = BankaHesabi("Emir", 1000, "10.01")

print(f"Kullanicinin adi : {B.kullanici}")

print(f"Kullanicinin bakiyesi: {B.get_bakiye()}")

yeni = int(input("Lutfen yeni degeri giriniz: "))
B.set_bakiye(yeni)
print(f"Kullanicinin bakiyesi: {B.get_bakiye()}")