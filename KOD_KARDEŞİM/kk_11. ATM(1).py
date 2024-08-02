from os import system
users = [
    { "isim" : "Emre" , "soyisim" : "Gazili" , "sifre" : "gaziliemre1" , "telefonu" : "5555555551" , "bakiyesi" : "15000" },
    { "isim" : "Hakan" , "soyisim" : "Kaleli" , "sifre" : "kalelihakan12", "telefonu" : "5555555552" , "bakiyesi" : "7500" },
    { "isim" : "Emir" , "soyisim" : "Üner" , "sifre" : "emirüner123" , "telefonu" : "5555555553" , "bakiyesi" : "6500" },
    { "isim" : "Mustafa" , "soyisim" : "Güzel" , "sifre" : "güzelmustafa1234" , "telefonu" : "5555555554" , "bakiyesi" : "8400" }
]

k_adi = input("Kullanıcı Adı: ")
k_sif = input("Şifre: ")
user = ""

for i in users:
    if (k_adi == i["isim"]) and (k_sif == i["sifre"]):
        user = i #doğru kullanıcı bulundu ve user'a aktarıldı 
        
        password = user["sifre"]
        name = user["isim"]
        surname = user["soyisim"]
        cash = int(user["bakiyesi"])

if user == "":
    print("Kullanıcı bulunamadı")
            
else:    
    while True:
        system("cls")
        print(f"Hoşgeldiniz {name} {surname}")
        print("""[1] Bakiye Sorgula
[2] Para Çek
[3] Para Yatır
[4] Çıkış Yap""")
        print("-----")
        islem = input("İşlem Seçin: ")
        if islem == "1":
            print("Hesab Bakiyeniz: {}".format(cash))
            input("Devam Etmak İçin Enter'a Bas")
        elif islem == "2":
            cekilecek_miktar = int(input("Çekilecek Miktarı Giriniz: "))
            if cekilecek_miktar <= cash:
                cash -= cekilecek_miktar
                print("İşlem Başarılı.Şu Anki Bakiyeniz: {}".format(cash))
                input("Devam Etmak İçin Enter'a Bas")
            else:
                print("Bakiye Yetersiz!")
                input("Devam Etmak İçin Enter'a Bas")
        elif islem == "3":
            yatırılacak_tutar = int(input("Yatırılacak Miktarı Giriniz: "))
            cash += yatırılacak_tutar
            print("İşlem Başarılı. Şu Anki Bakiyeniz: {}".format(cash))
            input("Devam Etmak İçin Enter'a Bas")
        elif islem == "4":
            print("Çıkış Yapılıyor...")
            break
        else:
            print("Hatalı İşlem. Lütfen Tekrar Deneyiniz.")

