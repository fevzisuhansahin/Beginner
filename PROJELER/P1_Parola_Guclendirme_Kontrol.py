gerekenler = {
    'harfler' :{
        'k_harf' : 'abcçdefgğhıijklmnoöpqrsştuüvwxyz',
        'b_harf' : 'ABCÇDEFGĞHIIJKLMNOÖPQRSŞTUÜVWXYZ'
    },
    'ozel_karakter' : '<>|.:,;`+@€´¨~-"!£^#$%½&/=*?-_|',
    'sayilar' : '0123456789'
}


while True:
    sifre = input("Lütfen parolanızı giriniz: ")
    
    if len(sifre) < 8:
        input("Şifreniz en az 8 karakterli olmalı. Tekrar denemek için 'ENTER' tuşuna basınız.")
        continue
    
    for oge in sifre:
        
    
    
# Regex kullanarak yap