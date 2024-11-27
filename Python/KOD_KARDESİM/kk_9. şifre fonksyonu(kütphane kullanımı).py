from random import choice
def password(uzunluk):
    kucuk_harfler = "abcdefghijklmnopqrstuvwxyz"
    buyuk_harfler = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    rakamlar = "0123456789"
    ozel_karakterler = "!#$%&/?-_+*~@£€"
    sifre = ""

    kharf = input("Şifrenizde Küçük Harf Olmasını İster Misiniz?(e/h): ")
    a = "Ee"
    if kharf in a:
        sifre += kucuk_harfler
    
    bharf = input("Şifrenizde Büyük Harf Olmasını İster Misiniz?(e/h): ")
    if bharf in a:
        sifre += buyuk_harfler

    rakam = input("Şifrenizde Rakam Olmasını İster Misiniz?(e/h): ")
    if rakam in a:
       sifre += rakamlar

    karakter = input("Şifrenizde Özel Karakter Olmasını İster Misiniz?(e/h): ") 
    if karakter in a:
        sifre += ozel_karakterler

    bos = ""
    if sifre == "":
        print("Şifre için seçim yapmadınız.")

    else:
        for i in range(uzunluk):
            bos += choice(sifre)
        print(f"Şifreniz: {bos}")

while True:
    password(int(input("Şifrenizin Kaç Haneli Olmasını İstersiniz? ")))


#şifre 8 haneden küçükse soruyor (while ile yapıldı)
"""
import random
def password(uzunluk):
    kucuk_harfler = "abcdefghijklmnopqrstuvwxyz"
    buyuk_harfler = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    rakamlar = "0123456789"
    ozel_karakterler = "!#$%&/?-_+*~@£€"
    sifre = ""
    a = "Ee"

    while True:
        if uzunluk < 8:
            karar = input("BU Uzunluktaki Şifre Güvenli Olmayabilir. Emin Misiniz?(e/h)")
            if karar not in a:
                uzunluk = int(input("İstediğiniz Uzunluğu Girin: "))
            else:
                break
        else:
            break
                
    kharf = input("Şifrenizde Küçük Harf Olmasını İster Misiniz?(e/h): ")
    if kharf in a:
        sifre += kucuk_harfler
    
    bharf = input("Şifrenizde Büyük Harf Olmasını İster Misiniz?(e/h): ")
    if bharf in a:
        sifre += buyuk_harfler

    rakam = input("Şifrenizde Rakam Olmasını İster Misiniz?(e/h): ")
    if rakam in a:
       sifre += rakamlar

    karakter = input("Şifrenizde Özel Karakter Olmasını İster Misiniz?(e/h): ") 
    if karakter in a:
        sifre += ozel_karakterler

    bos = ""
    if sifre == "":
        print("Şifre için seçim yapmadınız.")

    else:
        for i in range(uzunluk):
            bos += random.choice(sifre)
        print(f"Şifreniz: {bos}")

while True:
    password(int(input("Şifrenizin Kaç Haneli Olmasını İstersiniz? ")))

"""
"""
import random
def password(uzunluk):
    kucuk_harfler = "abcdefghijklmnopqrstuvwxyz"
    buyuk_harfler = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    rakamlar = "0123456789"
    ozel_karakterler = "!#$%&/?-_+*~@£€"
    sifre = ""
    a = "Ee"

    def sorgula(uzunluk):
        if uzunluk < 8:
            karar = input("BU Uzunluktaki Şifre Güvenli Olmayabilir. Devam etmek istediğinize emin misiniz?(e/h)")
            if karar not in a:
                uzunluk = int(input("istediğiniz uzunluğu giriniz: "))
                if uzunluk < 8:
                    sorgula(uzunluk)

    sorgula(uzunluk)   
                
    kharf = input("Şifrenizde Küçük Harf Olmasını İster Misiniz?(e/h): ")
    if kharf in a:
        sifre += kucuk_harfler
    
    bharf = input("Şifrenizde Büyük Harf Olmasını İster Misiniz?(e/h): ")
    if bharf in a:
        sifre += buyuk_harfler

    rakam = input("Şifrenizde Rakam Olmasını İster Misiniz?(e/h): ")
    if rakam in a:
       sifre += rakamlar

    karakter = input("Şifrenizde Özel Karakter Olmasını İster Misiniz?(e/h): ") 
    if karakter in a:
        sifre += ozel_karakterler

    bos = ""
    if sifre == "":
        print("Şifre için seçim yapmadınız.")

    else:
        for i in range(uzunluk):
            bos += random.choice(sifre)
        print(f"Şifreniz: {bos}")

while True:
    password(int(input("Şifrenizin Kaç Haneli Olmasını İstersiniz? ")))
"""