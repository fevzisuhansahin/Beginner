import cv2 as cv
import numpy as np

img = cv.imread(r"C:\Users\YUNUS\Desktop\Beginner\Egitim(CAS)\Goruntu_Isleme_Ders#2_part1\kurt.png")

img_averageBlur = cv.blur(img, (5,5))
img_gaussianBlur = cv.GaussianBlur(img, (5,5), 2)
img_medianBlur = cv.medianBlur(img, 5)
img_bilateralFilter = cv.bilateralFilter(img, d=5, sigmaColor= 75, sigmaSpace=75)

cv.imshow("Orjinal Resim", img)
cv.imshow("Average Filter", img_averageBlur)
cv.imshow("Gaussian Filter", img_gaussianBlur)
cv.imshow("Median Filter", img_medianBlur)
cv.imshow("Bilateral Filter", img_bilateralFilter)

cv.waitKey(0)
cv.destroyAllWindows()