class TeknolojikAlet:
    def __init__(self, marka, cikis_yili, fiyat):
        self.marka = marka
        self.cikis_yili = cikis_yili
        self.fiyat = fiyat

    def KendiniTanit(self):
        return f"{self.marka}, {self.fiyat} , {self.cikis_yili}"
    
class Bilgisayar(TeknolojikAlet):
    def __init__(self, marka, cikis_yili, fiyat, islemci, bellek):
        super().__init__(marka, cikis_yili, fiyat)
        self.islemci = islemci
        self.bellek = bellek

    def BilgiAl(self):
        self.islemci = input("Bilgisayarin islemcisi nedir?")
        self.bellek = input("Bilgisayarin bellek miktari nedir?")
        self.cikis_yili = 2020
        self.fiyat = 10000
        self.marka = "CAS"
        
    def KendiniTanit(self):
        print(f"{super().KendiniTanit()}, {self.islemci}, {self.bellek}")


# if __name__ == "__main__":
T = TeknolojikAlet("CAS", 2021, 15000)
B = Bilgisayar("Emir", 2023, 12000, "intel", "8GB")
B.BilgiAl()
B.KendiniTanit()