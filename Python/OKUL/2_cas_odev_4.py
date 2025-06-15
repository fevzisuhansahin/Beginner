import random

# Word lists
words_3 = ["gül", "bal", "çay"]
words_4 = ["masa", "elma", "kara"]
words_5 = ["kavun", "çanta", "kitap"]
words_6 = ["zeytin", "sünger", "duymaz"]

print("Kaç harfli kelime oynamak istersin? (3, 4, 5 ya da 6)")
while True:
    choice = input("Seçimin: ")

    if choice == "3":
        word_list = words_3
        break
    elif choice == "4":
        word_list = words_4
        break
    elif choice == "5":
        word_list = words_5
        break
    elif choice == "6":
        word_list = words_6
        break
    else:
        print("Lütfen sadece 3, 4, 5 veya 6 yaz.")

# Random choose a word
correct_word = random.choice(word_list)
length = len(correct_word)

print(f"\n{length} harfli bir kelime seçildi. Toplam 5 tahmin hakkın var!")

count = 0
while count < 5:
    guess = input(f"\n{count + 1}. tahmin: ").lower()

    if len(guess) != length:
        print(f"Lütfen {length} harfli bir kelime yaz.")
        continue

    if guess == correct_word:
        print("Tebrikler! Doğru bildin.")
        break

    result = ""

    for i in range(length):
        if guess[i] == correct_word[i]:
            result += "+"  # Correct position
        elif guess[i] in correct_word:
            result += "?"  # Correct letter but wrong position
        else:
            result += "-"  # Letter not in word

    print("Feedback:", result)
    count += 1

else:
    print(f"\nTahmin hakkın bitti. Doğru kelime: {correct_word}")
