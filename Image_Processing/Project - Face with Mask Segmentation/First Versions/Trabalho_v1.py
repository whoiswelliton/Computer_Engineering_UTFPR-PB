import numpy as np
from matplotlib import pyplot as plt

from skimage import io, feature
import skimage.data as data
import skimage.segmentation as seg
import skimage.filters as filters
import skimage.draw as draw
import skimage.color as color


from scipy import ndimage
from skimage import morphology as mm
from skimage.filters import gaussian, threshold_sauvola
from skimage.segmentation import active_contour
from skimage.segmentation import mark_boundaries
from skimage.segmentation import slic

# =============================================================================

def image_show2(image, nrows=1, ncols=1, cmap='gray'):
    fig, ax = plt.subplots(nrows = nrows, ncols = ncols)
    ax.imshow(image, cmap='gray')
    ax.axis('off')
    return fig, ax

def ajuste_contraste_parametr(im, high = 255, low = 0):
    #imagem deve ser em tons de cinza
    im2 = np.zeros(im.shape)
    
    im2[im <= low] = 0 #desnecessario

    im2[im > low] = 255*(im[im>low] - low)/(high-low)
    
    im2[im >= high] = 255
    
    return im2.astype("uint8")

# =============================================================================
image = io.imread('0307.jpeg')
image = image.astype("uint8")

# =============================================================================
# print(image.shape)
# lin,col,prof = image.shape
# imZ = np.zeros((lin,col,prof),'uint8')
# 
# for l in range(lin):
#     for c in range(col):
#         R,G,B = image[l,c,:]
#         
# plt.figure()
# plt.subplot(221)
# plt.xlabel('Original')
# plt.imshow(image)
# plt.subplot(222)
# plt.xlabel('R')
# plt.imshow(image[:,:,0], cmap='gray',vmin=0, vmax=255) #R
# plt.subplot(223)
# plt.xlabel('G')
# plt.imshow(image[:,:,1], cmap='gray',vmin=0, vmax=255)#G
# plt.subplot(224)
# plt.xlabel('B')
# plt.imshow(image[:,:,2], cmap='gray',vmin=0, vmax=255) #B
# =============================================================================


# CONVERTE A IMAGEM PARA A ESCALA DE CINZA E APLICA CONTRASTE
imGRAY = color.rgb2gray(image)*255
imCONT = ajuste_contraste_parametr(imGRAY, 215, 15)

# plt.figure()
# plt.subplot(221)
# plt.xlabel('Original')
# plt.imshow(imGRAY,cmap='gray',vmin=0, vmax=255);
# plt.subplot(222)
# plt.xlabel('+ Contraste')
# plt.imshow(imCONT,cmap='gray',vmin=0, vmax=255);


#THRESHOLD/LIMEARIZAÇÃO
imSAUVOLA = threshold_sauvola(imCONT,  window_size=15, k=0.05)
binary_sauvola = imCONT > imSAUVOLA

# plt.figure()
# plt.imshow(binary_sauvola, cmap=plt.cm.gray)
# plt.title('Sauvola Threshold')
# plt.axis('off')



#ACTIVE CONTOUR SEGMENTATION

def circle_points(resolution, center, radius):
    #Gera pontos os quais definem um círculo na imagem
    
    radians = np.linspace(0, 2*np.pi, resolution)
    c = center[1] + radius*np.cos(radians) #polar co-ordinates
    r = center[0] + radius*np.sin(radians)
    
    return np.array([c, r]).T
# Exclude last point because a closed path should not have duplicate points

#points = circle_points(100, [150, 300], 250)[:-1]

lin, col, prof = image.shape

if(col>lin):
    points = circle_points(100, [lin*0.35, col/2], (lin+col)/4)[:-1]

else:
    points = circle_points(100, [lin*0.35, col/2], (lin+col)/3)[:-1]

#snakecolor = seg.active_contour(binary_sauvola,points,alpha=0.09,beta=0.05, w_line=-0.5, w_edge=0, gamma=0.3)

#200pts - alpha 0.9
#100pts - alpha 0.29

snake = seg.active_contour(binary_sauvola,points,alpha=0.29,beta=0.05, gamma=0.3, w_line=0.5, w_edge=0.5)

fig, ax = image_show2(binary_sauvola)
ax.plot(points[:, 0], points[:, 1], '--r', lw=3)
ax.plot(snake[:, 0], snake[:, 1], '-b', lw=3);

seg = np.zeros(image.shape, 'bool')
l = snake[:,0].astype('int')
c = snake[:,1].astype('int')
seg[l,c] = 1
seg = mm.binary_dilation(seg, mm.disk(3))
seg = ndimage.binary_fill_holes(seg)

AND = np.bitwise_and(seg, binary_sauvola) 

fig, ax = image_show2(AND)
ax.plot(snake[:, 0], snake[:, 1], '-b', lw=3);


#RANDOM WALKER SEGMENTATION

# =============================================================================
# image_labels = np.zeros(image_gray.shape, dtype=np.uint8)
# 
# indices = draw.circle_perimeter(150, 300, 5) #from here
# image_labels[indices] = 1
# image_labels[points[:, 1].astype(np.int), points[:, 0].astype(np.int)] = 2
# #image_show(image_labels);
# 
# image_segmented = seg.random_walker(image_gray, image_labels, beta = 3000)
# fig, ax = image_show2(image_gray)
# ax.imshow(image_segmented == 1, alpha=0.3);
# 
# =============================================================================
