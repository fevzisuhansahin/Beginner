import random

# Kelime listeleri
kelimeler_3 = ["gül", "bal", "çay"]
kelimeler_4 = ["masa", "elma", "kara"]
kelimeler_5 = ["kavun", "çanta", "kitap"]
kelimeler_6 = ["zeytin", "sünger", "duymaz"]

print("Kaç harfli kelime oynamak istersin? (3, 4, 5 ya da 6)")
while True:
    secim = input("Seçimin: ")

    if secim == "3":
        kelime_listesi = kelimeler_3
        break
    elif secim == "4":
        kelime_listesi = kelimeler_4
        break
    elif secim == "5":
        kelime_listesi = kelimeler_5
        break
    elif secim == "6":
        kelime_listesi = kelimeler_6
        break
    else:
        print("Lütfen sadece 3, 4, 5 veya 6 yaz.")

# Rastgele bir kelime seçimi
dogru_kelime = random.choice(kelime_listesi)
kelime_uzunlugu = len(dogru_kelime)

print(f"\n{kelime_uzunlugu} harfli bir kelime seçildi. Toplam 5 tahmin hakkın var!")

hak = 0
while hak<5:
    tahmin = input(f"\n{hak + 1}. tahmin: ").lower()

    # Uzunluk kontrolü
    if len(tahmin) != kelime_uzunlugu:
        print(f"Lütfen {kelime_uzunlugu} harfli bir kelime yaz.")
        continue

    if tahmin == dogru_kelime:
        print("Tebrikler! Doğru bildin.")
        break

    sonuc = ""

    for i in range(kelime_uzunlugu):
        if tahmin[i] == dogru_kelime[i]:
            sonuc += "+"  # Yeri doğru
        elif tahmin[i] in dogru_kelime:
            sonuc += "?"  # Harf var ama yeri yanlış
        else:
            sonuc += "-"  # Harf yok

    print("Geri bildirim:", sonuc)
    hak += 1

else:
    print(f"\nTahmin hakkın bitti. Doğru kelime: {dogru_kelime}")
