yorum_birakanlar = ["Ismail Aydemir", "Uygar Aydin", "Naz Yagcioglu","Ferhat Ibrik","Ulas Acil", "Bilal Kurucay"]
moderator = "Ferhat Ibrik"

kullanici_sayi = 0
moderator_sayi = 0

for isim in yorum_birakanlar:
    ad, soyad = isim.split()[0], isim.split()[1]  # burda olduğu gibi ikili tanımlama yapıabilir
    if(isim == moderator):
        moderator_sayi+=1
        print('{0}. Moderatörün Adi {1}, Soyadi {2}'.format(moderator_sayi,ad,soyad))
    else:
        kullanici_sayi+=1
        print('{0}. Katilimcinin Adi {1}, Soyadi {2}'.format(kullanici_sayi,ad,soyad))    
        


liste = [[0,1],[2,3],[4,5]]  

for a,b in liste:  # bu şekilde listedeki ikili ögelerden de veri çekebiliriz
    print(a*b)
    
"""liste1 = [[0,1],[2,3],[4,5,6]]

for a,b in liste1:
    print(a,b)
"""
                                    # bu iki örnekte de bazı ögelerde 'a,b' ikilisi bulamayacağı için hata verir
"""liste1 = [[0,1],[2,3],[4,5],"x"]

for a,b in liste1:
    print(a,b)
"""