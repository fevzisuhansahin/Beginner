import cv2 as cv
import numpy as np

img = cv.imread(r"C:\Users\YUNUS\Desktop\Beginner\Egitim(CAS)\Goruntu_Isleme_Ders#2_part1\kurt.png")
img = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

ret1, simple_thresh = cv.threshold(img, 105, 255, cv.THRESH_BINARY)

adaptive_thresh = cv.adaptiveThreshold(img, 255, cv.ADAPTIVE_THRESH_MEAN_C, cv.THRESH_BINARY, 11, 3)

ret2 , otsu_thresh = cv.threshold(img, 0, 255, cv.THRESH_BINARY + cv.THRESH_OTSU)


print(f"1. esik deger: {ret1}")
print(f"2. esik deger: {ret2}")

cv.imshow("Orjinal", img)
cv.imshow("Simple Threshold", simple_thresh)
cv.imshow("Adaptive Threshold", adaptive_thresh)
cv.imshow("Otsu Threshold", otsu_thresh)


cv.waitKey(0)
cv.destroyAllWindows()