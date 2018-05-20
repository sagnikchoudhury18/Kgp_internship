import cv2
import numpy as np
arr=[]
k=0
arr_points=[]
rgb_img = cv2.imread('E:/kgp_internship/opencv_material/images/standard_test_images/ball1.jpg')
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
#print(closingcanny[150,150])         #to access individual pixel value
#print(len(closingcanny[0]));
#print(closingcanny[93][293])              #value of points on row 150th of the image
cv2.imshow('closingcanny',closingcanny)
for i in range(0,height1,1):            #i will be used for row traversal whereas j will be used for colomns
    for j in range(0,width-4,1):
        if((closingcanny[i][j]>200)):
            k+=1
            arr.append([[i],[j]])
            #print(i,j)
            print('\n')
            arr_points.append(arr)
            if(k==2):
                break              #got both the points in one row
for i in range(0,len(arr_points)):
    print(arr_points[i])
                
