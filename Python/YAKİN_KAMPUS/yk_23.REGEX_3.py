# Ifade ####### Aciklama ######## Örnek ############# Patern ####
# --------------------------------------------------------------#
#   |   ########  veya   #######  slm  #########    selam|slm   #
#   ^    ####### baslar #######  Ahmet  ##########   ^\w+      ##
#   $   ########  biter   ##### base42   ########     \d$       #
#   .   ######  herhangi  #####  abcdef  ########      .*       #
#   \   ########  esc     #####  (not)   ########   \(\w{3}\)   #
# --------------------------------------------------------------#

import re

def mesaj_hissi_bul(mesaj):
    hisler = []
    
    pozitif_patern = r"[M|m]erhaba|[S|s]elam|[A|a]şk|[S|s]evgi|[D|d]ost|[K|k]ardeş|:\)+" # ':)' bu ifadeyi tanımlamak 
    # için ':\)' esc işaretini kullanıyoruz. Yoksa parantezi str olarak algılamaz
    negatif_patern = r"[L|l]an|[A|a]ptal|[Y|y]eter|[B|b]ırak"
    heyecanli_patern = r"!|[!|?]{2,}$"
    sakin_patern = r"^[T|t]abi|^[H|h]ayhay"
    emin_patern = r"[K|k]esin|[T|t]abi|[E|e]lbet"
    kararsiz_patern = r"[B|b]elki|[S|s]anırım"
    
    # Paternler bu şekilde de yazılabilir
    """
    pozitif_patern = r"[Mm]erhaba|[Ss]elam|[Aa]şk|[Ss]evgi|[Dd]ost|[Kk]ardeş|:\)+"
    negatif_patern = r"[Ll]an|[Aa]ptal|[Yy]eter|[Bb]ırak"
    heyecanli_patern = r"!|[!?]{2,}$"
    sakin_patern = r"^[Tt]abi|^[Hh]ayhay"
    emin_patern = r"[Kk]esin|[Tt]abi|[Ee]lbet"
    kararsiz_patern = r"[Bb]elki|[Ss]anırım"
    """
    
    if re.search(pozitif_patern, mesaj):  # bir mesajda birden fazla his olabileceğinden elif kullanmadım
        hisler.append("Pozitif")
    if re.search(negatif_patern, mesaj):
        hisler.append("Negatif")
    if re.search(heyecanli_patern, mesaj):
        hisler.append("Heyecanlı")
    if re.search(sakin_patern, mesaj):
        hisler.append("Sakin")
    if re.search(emin_patern, mesaj):
        hisler.append("Emin")
    if re.search(kararsiz_patern, mesaj):
        hisler.append("Kararsız")
        
    return hisler

cumle1 = "Naber abi? :)             "
cumle2 = "tabiii ki buyrun          "
cumle3 = "Saçmalamayı bırak artık!  "
cumle4 = "Belki yarından da yakın..."
cumle5 = "Elbet birgün buluşacağız  "
cumleler = [cumle1, cumle2, cumle3, cumle4, cumle5]

for i in cumleler:
    print(i , "\t" , mesaj_hissi_bul(i))
    print(f"{i}\t{mesaj_hissi_bul(i)}")