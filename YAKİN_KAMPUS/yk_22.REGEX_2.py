## Ifade ####### Aciklama ######## Örnek ############# Patern #####
# --------------------------------------------------------------###
#  {5}   ########  adet  #######  aaaaa  #########    \w{5}     ###
#  {3,4} #######   veya  #######   abc  ##########   \w{3,4}     ##
#  {2,}  ########  en az  ##### 198721321 ########    \d{2,}     ##
#    *   ###  0 ya da fazla #######  x  ##########     \w*        #
#    +   ### 1 ya da fazla ######  Ahmet1  #######    \w+\d+     ##
#    ?   #####  ya 1 ya hic ####### Mura #########     Murat?     #
# --------------------------------------------------------------- #

import re

ornek = "Benim tel no: 0507 807 27 01"
patern = r"\d{3,}\s\d{3}\s\d{2}\s\d{2}"

eslesme = re.search(patern, ornek)
print(eslesme)

ornek1 = "En sevdigim kanal base42."
patern1 = r"\w{5,}"

for eslesme in re.finditer(patern1, ornek1):
    print(eslesme.group(), eslesme.span())
    
ornek2 = "Benim tel no: 0507 807 27 01"
patern2 = r"\d?" # çıktıda rakam olsa da olmasa da her karakter olacak

for eslesme in re.finditer(patern2, ornek2):
    print(eslesme.group(), eslesme.span())
    
ornek3 = "Benim tel no: 0507 807 27 01"
patern3 = r"\d+"

for eslesme in re.finditer(patern3, ornek3):
    print(eslesme.group(), eslesme.span())

ornek4 = "En sevdigim kanal base42."
patern4 = r"\w*\d+"

for eslesme in re.finditer(patern4, ornek4):
    print(eslesme.group(), eslesme.span())
    
# GSM Operatörleri:
# 54...         -> Vodafone
# 501,505,506   -> AVEA
# 53...         -> Turkcell

def gsm_operatoru_bul(tel_no):
    patern5 = r"(\d{3})(\s)(\d{3})(\s)(\d{2})(\s)(\d{2})" # ilk \d ye en az 3(\d{3,}) demedim baştaki 0'ı almamak için 
    eslesme = re.search(patern5, tel_no)
    
    if eslesme:
        kod = eslesme[0]
        if kod.startswith("54"):
            print("Vodafone")
        elif kod.startswith("50"):
            print("AVEA")
        elif kod.startswith("53"):
            print("Turkcell")
        else:
            print("Operatör bulunamadı")
    else:
        print("Herhangi bir numara bulunamadı")
        
gsm_operatoru_bul(input("Numara aratmek istediğiniz metni yazın: "))