import cv2

img = cv2.imread('Franklin-in-the-100-bill.jpg')
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
cv2.imshow('image', gray)
cv2.waitKey(0)
height, width = img.shape[0:2]