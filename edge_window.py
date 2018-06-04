import math
import cv2
import numpy as np
from matplotlib import pyplot as plt

img1=cv2.imread('E:/kgp_internship/opencv_material/images/standard_test_images/ball11.jpg',0)

blur=cv2.blur(img1,(3,3))

#cv2.imshow('blur',blur)
edges1=cv2.Canny(blur,100,200)
height1,width1=edges1.shape
print(height1,width1)
op=np.zeros((height1,width1))

print(edges1[139][110])
cv2.imshow('edges',edges1)

flg=0;
center=[0,0]
points=[]
for i in range(0,height1):
    for j in range(0,width1):
        if(edges1[i,j]==255):
            center=[i,j]
            points.append(center)
            flg=1
            break
    if flg==1:
        break;
    
i1=i        #value of y coordinate of  origin
j1=j        #value of x coordinate of origin


flag=0      #to check if point is detected or not

print(str(i1)+" "+str(j1))
count=0
while count<2000:
    flag=0
    count+=1
    if((count>50)and(i==i1)and(j==j1)):
        print("Break")
        break
    if(edges1[i-1,j-1]==255) and [i-1,j-1] not in(points):
        points.append([i-1,j-1])
        i=i-1
        j=j-1
        flag=1
        print("First if")
    elif(edges1[i,j-1]==255)and [i,j-1] not in(points):
        points.append([i,j-1])
        j=j-1
        flag=1
        print("Second if")
    elif(edges1[i+1,j-1]==255)and [i+1,j-1] not in(points):
        points.append([i+1,j-1])
        i=i+1
        j=j-1
        flag=1
        print("Thrird if")
    elif(edges1[i-1,j]==255)and [i-1,j] not in (points):
        points.append([i-1,j])
        i=i-1
        flag=1
        print("Fourth if")
    elif(edges1[i+1,j]==255)and [i+1,j] not in (points):
        points.append([i+1,j])
        i=i+1
        print("Fifth if")
        flag=1
    elif(edges1[i-1,j+1]==255)and [i-1,j+1] not in (points):
        points.append([i-1,j+1])
        i=i-1
        j=j+1
        flag=1
        print("Sixth if")
    elif(edges1[i,j+1]==255)and [i,j+1] not in (points):
        points.append([i,j+1])
        j=j+1
        flag=1
        print("Seventh if")
    elif(edges1[i+1,j+1]==255)and [i+1,j+1] not in (points):
        points.append([i+1,j+1])
        i=i+1
        j=j+1
        flag=1
        print("Eigth if")
    while(flag==0):
        print("No point found")
        if(edges1[i-2,j+2]==255)and [i-2,j+2] not in(points):
            i=i-2
            j=j+2
            flag=1
            print("flag 0 first if")
            break
        elif(edges1[i,j+2]==255)and [i,j+2] not in (points):
            j+=2
            flag=1
            print("flag 0 second if")
            break
        elif(edges1[i+2,j+2]==255)and [i+2,j+2] not in (points):
            i+=2
            j+=2
            flag=1
            print("flag 0 third if")
            break
        elif(edges1[i+2,j]==255)and [i+2,j] not in (points):
            i+=2
            flag=1
            print("flag 0 fourth if")
            break
        elif(edges1[i+2,j-2]==255)and [i+2,j-2] not in (points):
            i+=2
            j-=2
            flag=1
            print("flag 0 fifth if")
            break
        elif(edges1[i,j-2]==255) and [i,j-2] not in (points):
            j-=2
            flag=1
            print("flag 0 sixth if")
            break
        elif(edges1[i-2,j-2]==255) and [i-2,j-2] not in (points):
            i-=2
            j-=2
            flag=1
            print("flag 0 seveth if")
            break
        elif(edges1[i-2,j]==255) and [i-2,j] not in (points):
            i-=2
            flag=1
            print("flag 0 eigth if")
            break
        elif(edges1[i-3,j+3]==255)and [i-3,j+3] not in (points):
            i=i-3
            j=j+3
            flag=1
            print("flag 0 ninth if")
            break
        elif(edges1[i,j+3]==255)and [i,j+3] not in (points):
            j+=3
            flag=1
            break
        elif(edges1[i+3,j+3]==255)and [i+3,j+3] not in (points):
            i+=3
            j+=3
            flag=1
            print("flag 0 tenth if")
            break
        elif(edges1[i+3,j]==255)and [i+3,j] not in (points):
            i+=3
            flag=1
            break
        elif(edges1[i+3,j-3]==255)and [i+3,j-3] not in (points):
            i+=3
            j-=3
            flag=1
            print("flag 0 eleventh if")
            break
        elif(edges1[i,j-3]==255) and [i,j-3] not in (points):
            j-=3
            flag=1
            print("flag 0 twelvth if")
            break
        elif(edges1[i-3,j-3]==255)and [i-3,j-3] not in (points):
            i-=3
            j-=3
            flag=1
            print("flag 0 thirteenth if")
            break
        elif(edges1[i-3,j]==255)and [i-3,j] not in (points):
            i-=3
            flag=1
            print("flag 0 fourteenth if")
            break
        
        
    #print(str(i)+" "+str(j))
    #cv2.imshow('op',op)      
    op[i,j]=255;
    points.append([i,j])
print(points)
cv2.imshow('op',op)    
    

