import cv2
import numpy as np

img=cv2.imread("E:\kgp_internship\opencv_material\images\standard_test_images\lena_color_256.tif",0)
while True:
    laplacian=cv2.Laplacian(img,cv2.CV_64F)
    edges=cv2.Canny(img,200,400)
    sobelx=cv2.Sobel(edges,cv2.CV_64F,1,0,ksize=5)
    sobely=cv2.Sobel(edges,cv2.CV_64F,0,1,ksize=5)
    cv2.imshow('original',img)
    cv2.imshow('laplacian',laplacian)
    cv2.imshow('sobelx',sobelx)
    cv2.imshow('sobely',sobely)
    cv2.imshow('edges',edges)
    k=cv2.waitKey(5)& 0xFF
    if k==27:
        break
cv2.destroyAllWindows()
#img.release()
