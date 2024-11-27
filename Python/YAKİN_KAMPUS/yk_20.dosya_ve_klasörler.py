# OS MODÜLÜ

# Navigasyon ve İçerik Listeleme

import os # os kütüphanesini çağırdım

print(os.getcwd()) # get current working directory
print(os.listdir()) # klasörün altındaki ögeleri listeler. parametre girmezsek bulunduğumuz klasöre bakar (list directly)
print(os.listdir("C:\\Games"))
os.chdir("C:\\Games") # bu komut sizin halihazırda bulunduğunuz konumu girdiğiniz parametreye göre değiştirir (change directly)
print(os.listdir()) # konumu değiştiği içn biraz önceki listdir ile farklı çıktı alacak
os.chdir("C:\\Users\\YUNUS\\Desktop\\Beginner") # tekrar eski konumuna aldım

dosyalar = os.listdir("C:\\Users")
for i in dosyalar:
    print(i , end = "???")

# Yeni Eleman Olusturma ve Silme

# klasör
os.mkdir("C:\\Users\\YUNUS\\Desktop\\Beginner\\deneme_klasoru") # yeni klasör oluşturma (make directly)
print(os.listdir())
os.rmdir("C:\\Users\\YUNUS\\Desktop\\Beginner\\deneme_klasoru") # klasör silme (remove directly)

# dosya

## os.O_RDONLY − Read Only      - Sadece Oku
## os.O_WRONLY − Write Only     - Sadece Yaz
## os.O_RDWR   − Read and Write - Oku ve Yaz
## os.O_CREAT  - Create         - Olustur

dosya = os.open("dosya.txt", os.O_RDWR | os.O_CREAT) # dosya.txt adında bir dosya açtım. virgülden sonraki kısı da özelikleri
os.write(dosya, "Merhaba Dünya!".encode()) # os.write komutu byte türü ile işlem yapar. bu yüzden encode() yazmaszak TypeError verir
uzunluk = os.stat(dosya).st_size
os.lseek(dosya, 0, os.SEEK_SET) # imleci başa çekme işlemi: https://chatgpt.com/share/2e367e46-1afa-4c0c-8099-c0e4d17695e9
icerik = os.read(dosya, uzunluk) # read komutu okunacak dosyanın ismini bi de kaç karakter okunacağını içerir
print(icerik.decode())
os.close(dosya) # ve en sonunda bu işlem dizinini kapattım
os.unlink("dosya.txt")

# Isim degistirme

os.mkdir("C:\\Users\\YUNUS\\Desktop\\Beginner\\isim_degisecek")
print(os.listdir())
os.rename("isim_degisecek" , "isim_degisti")
print(os.listdir())
os.rmdir("C:\\Users\\YUNUS\\Desktop\\Beginner\\isim_degisti")
