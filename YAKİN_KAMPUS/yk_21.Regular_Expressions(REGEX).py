import re

cumle = "Bu cümlede cümlede iki kez tekrar eden bir kelime var, ancak diğer kelimeler bir kez geçiyor."
patern = r"cümle" # r harfi ham string yapar: https://chatgpt.com/share/d280d562-99f8-458b-bfa6-d134c85c1738

eslesme = re.search(patern, cumle) # search komutu ilk eşleşmeden sonra durur
print(eslesme)
print(eslesme.span()) # span indexleri verir
print(eslesme.group()) # group eşleşen kelimeyi verir
print(eslesme.start()) # başlangıç indexi
print(eslesme.end()) # bitiş indexi

# Çoklu Eşleşmeler(match)

for i in re.findall(patern, cumle): # findall sadece eşleşen kelimeleri yazdırır
    print(i)
    
for i in re.finditer(patern, cumle): # finditer ise atributeleri de içerir
    print(i.span(), i.group())
    
# Dinamik Kullanım

# Ifade ########## Aciklama ######## Örnek ########### Patern ####
# --------------------------------------------------------------##
#  \d   #########   rakam  #######  base42  #########  base\d\d ##
#  \w   ########   karakter  #####   R2-D2  ######### \w\w\w\w\w #
#  \s   ########    bosluk  ###### Ping Pong ######## Ping\sPong #
#  \D   #######   rakam degil  #####  base  #########  \D\D\D\D ##
#  \W   #####   karakter degil  ###   R2D2  ######### \W\W\W\W ###
#  \S   #####    bosluk degil ##### PingPong ### \S\S\S\S\S\S\S\S#

cumle1 = "En sevdiğim kanal base42"
patern1 = r"base\d\d"
eslesme1 = re.search(patern1, cumle1)
print(eslesme1)

cumle2 = "Tel no: 0507 807 27 01"
patern2 = r"\d\d\d\d\s\d\d\d\s\d\d\s\d\d"
eslesme2 = re.search(patern2, cumle2)
print(eslesme2)