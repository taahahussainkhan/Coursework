import numpy as np
import cv2

img1=cv2.imread('grayscale.jpg',0) 

img = np.array(img1)
# Create an empty image
result = np.zeros(img.shape, np.uint8)
# Loop through the pixels
for index, pixel in np.ndenumerate(img):
    x, y = index
    # Get the 6th, 7th, 8th bit of the current pixel
    sixth = img[x,y] & (2 ** 5)
    seventh = img[x,y] & (2 ** 6)
    eight = img[x,y] & (2 ** 7)
    # Save the Most significant bit of the current pixel of result image
    result[x,y] = sixth | seventh | eight


cv2.imwrite('sixth-seventh-eight.jpg', result)
