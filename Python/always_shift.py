from pynput.keyboard import Key, Controller
import time

keyboard = Controller()
shift_pressed = False

print("Komut girin (on / off / exit):")

while True:
    command = input(">>> ").strip().lower()

    if command == "on":
        if not shift_pressed:
            keyboard.press(Key.shift)
            shift_pressed = True
            print("Shift tuşuna basıldı.")
        else:
            print("Shift zaten basılı.")

    elif command == "off":
        if shift_pressed:
            keyboard.release(Key.shift)
            shift_pressed = False
            print("Shift tuşu bırakıldı.")
        else:
            print("Shift zaten serbest.")

    elif command == "exit":
        if shift_pressed:
            keyboard.release(Key.shift)
            print("Shift tuşu bırakıldı.")
        print("Programdan çıkılıyor.")
        break

    else:
        print("Geçersiz komut. 'on', 'off' veya 'exit' yazın.")