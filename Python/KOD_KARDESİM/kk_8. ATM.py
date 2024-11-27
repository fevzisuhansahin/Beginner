print("""Coder Bank ATM İşlem Listesi
      [1]Baki'ye Sor
      [2]Para Yatır
      [3]Para Çek
      [Ç]Çıkış Yap""")
bakiye = int(0)

while True:
      numara = input("İşlem numarasını seçiniz: ")

      if numara == "1":
            print("Hesap Bakiyeniz: ", bakiye)

      elif numara == "2":
            artıs= int(input("Yatırmak İstediğiniz Tutarı Giriniz: "))
            bakiye += artıs
            print("İşlem Başarılı.Hesabınızda Bulunan Tutar: ", bakiye," TL")

      elif numara == "3":
            azalıs = int(input("Çekmek İstediğiniz Tutarı Giriniz: "))
            if azalıs > bakiye:
                  print("Bakiye Yetersiz.")
            else:
                  bakiye -= azalıs
                  print("İşlem Başarılı.Hesabınızda Bulunan Tutar: ", bakiye," TL")

      elif numara == "ç" or "Ç":
            print("Çıkış Yapılıyor...")
            break

      else:
            print("Lütfen İşlemi Sadece İşlem Listesindeki İşlemlerden Seçiniz.")