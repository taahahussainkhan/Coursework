from PIL import Image
import numpy as np
import cv2

img1=cv2.imread('grayscale.jpg',0) 

img = np.array(img1)
# Create an empty image
result = np.zeros(img.shape, np.uint8)
# Loop through the pixels
for index, pixel in np.ndenumerate(img):
    x, y = index
    # Get the Most significant bit of the current pixel
    p = img[x,y] & (128)
    # Shift the bit to the right by 7 to get the least significant bit
    p = p >> 7
    # Set the least significan bit of the current pixel to most significant bit
    result[x,y] = p
cv2.imwrite('grayscale-MSB-to-LSB.jpg', result)
