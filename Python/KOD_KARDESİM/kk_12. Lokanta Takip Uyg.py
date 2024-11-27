from os import system
masalar = {} # sisteme masalar kalsörü açtık
for i in range(1,11):
    masalar[i] = 0  # sisteme 10 tane 0 tl olan masa açtık

Tip = 0
a = "Ee"

while True:
    system("cls") # bu kod input'da enter'a basınca önceki durumları temizliyor
    print("      *MASALAR*")
    for i in range(1,11):
        print(f"{i}. Masanın Hesabı: {masalar[i]}")
    print(f"Tip Box: {Tip}")
    print("""    
   İŞLEMLER
[1] Hesap Ekle
[2] Hesap Sil
[3] Çıkış Yap""")
    
    islem = int(input("İşlem Seç: "))
    if islem == 1:
        masa_no = int(input("Masa No Girin: "))
        eklenecek = int(input("Miktar Giriniz: "))
        masalar[masa_no] += eklenecek
        print(f"{masa_no}. masaya {eklenecek} TL eklendi")
        input("Devam Etmek İçin Enter'a Bas")
    
    elif islem == 2:
        masa_no = int(input("Masa No Girin: "))
        cıkarılacak = int(input("Miktar Girin: "))
        if cıkarılacak <= masalar[masa_no]:
            masalar[masa_no] -= cıkarılacak
            print(f"{masa_no}. masanın {cıkarılacak} TL'si ödendi")
            input("Devam Etmek İçin Enter'a Bas")
        else:
            x = cıkarılacak - masalar[masa_no]
            karar=input("Para üstünü Tip olarak almak ister misiniz?(e/h): ")
            if karar in a:
                Tip += x
                masalar[masa_no] -= cıkarılacak - x     
                print(f"Tip Box'a {x} TL eklendi")
            else:
                masalar[masa_no] -= cıkarılacak - x     
                print(f"Para üstü {x}")
            input("Devam Etmek İçin Enter'a Bas")

    elif islem == 3:
        print("Çıkış Yapıldı")
        break

    else:
        print("Böyle Bir İşlem Bulunamadı. Lütfen Tekrar Deneyin")
        input("Tekrar Denemek İçin Enter'a Basın")