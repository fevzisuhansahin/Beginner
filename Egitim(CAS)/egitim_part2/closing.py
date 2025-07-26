import cv2
import numpy as np

img = cv2.imread(r"C:\Users\YUNUS\Desktop\Beginner\Egitim(CAS)\egitim_part2\closing.png")

kernel = np.ones((7,7), np.uint8)

closing = cv2.morphologyEx(img, cv2.MORPH_CLOSE, kernel)

cv2.imshow("Orj", img)
cv2.imshow("closing", closing)

cv2.waitKey(0)
cv2.destroyAllWindows()