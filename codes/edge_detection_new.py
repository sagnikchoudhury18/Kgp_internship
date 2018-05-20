import cv2
import numpy as np
rgb_img = cv2.imread('E:/kgp_internship/opencv_material/images/misc/4.2.01.tiff')
print(type(rgb_img))
#cv2.imshow('closing',rgb_img)
height, width,channels = rgb_img.shape
gray_img = cv2.cvtColor(rgb_img, cv2.COLOR_BGR2GRAY)
white_padding = np.zeros((50, width, 3))
white_padding[:, :] = [255, 255, 255]
rgb_img = np.row_stack((white_padding, rgb_img))
gray_img = 255 - gray_img
gray_img[gray_img > 100] = 255
gray_img[gray_img <= 100] = 0
black_padding = np.zeros((50, width))
gray_img = np.row_stack((black_padding, gray_img))
#cv2.imshow('gray_img',gray_img)
kernel = np.ones((30, 30), np.uint8)
closing = cv2.morphologyEx(rgb_img, cv2.MORPH_CLOSE, kernel)
#cv2.imshow('closing',closing)
#edges = cv2.Canny(closing, 200, 400)
closingCopy = np.uint8(closing)
closingcanny = cv2.Canny(closingCopy,100,200)
height1, width1 = closingcanny.shape
print(height1,width1)
#print(len(closingcanny[0]));
print(closingcanny[200])              #value of points on row 150th of the image
cv2.imshow('closingcanny',closingcanny)
