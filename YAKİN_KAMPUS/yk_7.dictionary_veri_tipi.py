dict1 = {                   # dict veri tipi bir ögenin farklı boyuttaki verilerini saklar 
    'ad' : 'fevzi',
    'yas' : '19',
    'konum' : 'nigde'
}

print(dict1)

dict2 = {
    'ad' : 'fevzi',
    'yas' : '19',
    'dogdugu_yer' : 'eregli',
    'yasadıgı_yer' : 'nigde'
}

print(dict2)

dict3 = {
    'ad' : 'fevzi',
    'yas' : '19',
    'konum' : {
        'dogdugu_yer' : 'eregli',
        'yasadıgı_yer' : 'nigde'
    }
}

print(dict3)

# dict'den veri çekme
print(dict1['ad'])
print(dict2['yas'])
print(dict3['konum']['yasadıgı_yer'])

print(dict1.get('ad'))
print(dict2.get('yas'))
print(dict3.get('konum').get('yasadıgı_yer'))

print(dict2.keys())
print(dict2.values())
print(dict2.items())

# dict'e veri ekleme

dictionary = {"ad":1 , "yas":2 , "cash":3}
print(dictionary)
dictionary["soyad"] = 4
print(dictionary)