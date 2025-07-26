import cv2 as cv
import matplotlib.pyplot as plt

img = cv.imread(r"c:\Users\YUNUS\Desktop\Beginner\Python\Goruntu_Isleme\overexpos.jpg")
if img is None:
    raise IOError("Image is not found!")

b, g, r = cv.split(img)

# equalization process
b_eq = cv.equalizeHist(b)
g_eq = cv.equalizeHist(g)
r_eq = cv.equalizeHist(r)

img_eq = cv.merge([b_eq,g_eq,r_eq])

cv.imshow("Source", img)
cv.imshow("Equal Image", img_eq)
cv.imwrite(r"c:\Users\YUNUS\Desktop\Beginner\Python\Goruntu_Isleme\overexpos_equal.jpg", img_eq)

# drawing histograms
colours = ['b', 'g', 'r']
channel_org = [b, g, r]
channel_eq = [b_eq, g_eq, r_eq]

plt.figure(figsize=(12, 6))
for i,colour in enumerate(colours):
    # drawing original channel hist
    plt.subplot(2, 3, i+1)
    hist = cv.calcHist(channel_org[i], [0], None, [256], [0, 256])
    plt.plot(hist, color=colour)
    plt.title(f"{colour.upper()} - Original")
    plt.xlim([0, 256])
    # drawing equal channel hist
    plt.subplot(2, 3, i+4)
    hist_eq = cv.calcHist(channel_eq[i], [0], None, [256], [0, 256])
    plt.plot(hist_eq, color=colour)
    plt.title(f"{colour.upper()} - Equal")
    plt.xlim([0, 256])

plt.tight_layout()
plt.show()

cv.waitKey(0)
cv.destroyAllWindows()