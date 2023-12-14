import numpy as np
import cv2

img1=cv2.imread('grayscale.jpg',0) 

img = np.array(img1)
# Create an empty image
result = np.zeros(img.shape, np.uint8)
# Loop through the pixels
for index, pixel in np.ndenumerate(img):
    x, y = index
    # Get the 4th, 5th and 6th bit of the current pixel
    third = img[x,y] & (2 ** 2)
    fourth = img[x,y] & (2 ** 3)
    fifth = img[x,y] & (2 ** 4)
    # Save the Most significant bit of the current pixel of result image
    result[x,y] = third | fourth | fifth

cv2.imwrite('third-fourth-fifth.jpg', result)
