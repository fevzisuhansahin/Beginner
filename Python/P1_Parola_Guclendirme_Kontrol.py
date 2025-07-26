gereken = {
    'harf' :{
        'k_harf' : 'abcçdefgğhıijklmnoöpqrsştuüvwxyz',
        'b_harf' : 'ABCÇDEFGĞHIIJKLMNOÖPQRSŞTUÜVWXYZ'
    },
    'ozel_karakter' : '<>|.:,;`+@€´¨~-"!£^#$%½&/=*?-_|',
    'rakam' : '0123456789',
    'bosluk' : ' '
}

oge = {
    
    'k_harf' : 0,
    'b_harf' : 0,
    'rakam' : 0,
    'ozel_karakter' : 0,
}

bosluk = " "
sifre = input("Lütfen şifrenizi giriniz: ")

if len(sifre) < 8: 
    print("Şireniz çok kısa.")
    quit()

if bosluk in sifre:
    print("Şifre boşluk içermemeli.")
    quit()

for i in sifre:
    if i in gereken['harf']['k_harf']:
        oge['k_harf'] += 1
    elif i in gereken['harf']['b_harf']:
        oge['b_harf'] += 1
    elif i in gereken['rakam']:                   
        oge['rakam'] += 1
    elif i in gereken['ozel_karakter']:
        oge['ozel_karakter'] += 1
    
    
sifir_sayisi = list(oge.values()).count(0)
yuzdelik = (len(oge.keys()) - sifir_sayisi)/len(oge.keys())*100
           
if oge['k_harf'] == 0:
    print("Şifrenize küçük harf eklemelisiniz.")
if oge['b_harf'] == 0:
    print("Şifrenize büyük harf eklemelisiniz.")
if oge['rakam'] == 0:
    print("Şifrenize rakam eklemelisiniz.")
if oge['ozel_karakter'] == 0:
  print("Şifrenize özel karakter eklemelisiniz.")
print(f"Şifreniz '%{yuzdelik}' güvenlidir.")
print("|" , float(yuzdelik/100) * "#" , float(100 - (yuzdelik/100)) * " " , "|")