import cv2
import numpy as np

img = cv2.imread(r"C:\Users\YUNUS\Desktop\Beginner\Egitim(CAS)\egitim_part2\lenna.png")

canny = cv2.Canny(img, 100, 200)

cv2.imshow("lenna", img)
cv2.imshow("canny", canny)
cv2.waitKey(0)
cv2.destroyAllWindows()