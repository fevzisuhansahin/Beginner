class Hazirlik():
    def __init__(self , ad , soyad , yas):
        self.adi = ad
        self.soyadi = soyad
        self.yasi = yas
        
arif = Hazirlik("Arif Tuna" , "Ünal" , 19)
fevzi = Hazirlik("Fevzi Sühan" , "Şahin" , 18)
bahce = Hazirlik("Mustafa Hilmi" , "Bahçe" , 20)
asim = Hazirlik("Yahya Asım" , "Döner" , 19)

talebeler = [arif,fevzi,bahce,asim]

for i in talebeler:
    print(f"""Adı: {i.adi}
Soyadı: {i.soyadi}
Yaşı: {i.yasi}""")
    