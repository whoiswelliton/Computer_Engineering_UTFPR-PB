import numpy as np
import skimage.data as data
import skimage.segmentation as seg
import skimage.filters as filters
import skimage.draw as draw
import skimage.color as color

from matplotlib import pyplot as plt
from scipy import ndimage
from skimage import io, filters
from skimage import morphology as mm
from skimage import io, feature
from skimage.filters import gaussian, threshold_sauvola
from skimage.segmentation import active_contour, mark_boundaries

# =============================================================================
#FUNÇÕES ÚTEIS

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

#image = io.imread('Dataset/Mascara/5215.jpg')
#image = io.imread('Dataset/Sem/5307.jpg')
image = io.imread('5584.jpg')
image = image.astype("uint8")

# =============================================================================
# CONVERTE A IMAGEM PARA A ESCALA DE CINZA E APLICA CONTRASTE

imGRAY = color.rgb2gray(image)*255
imCONT = ajuste_contraste_parametr(imGRAY, 215, 15)

#THRESHOLD/LIMEARIZAÇÃO

imSAUVOLA = threshold_sauvola(imCONT,  window_size=15, k=0.05)
binary_sauvola = imCONT > imSAUVOLA

#ACTIVE CONTOUR SEGMENTATION

def circle_points(resolution, center, radius):
    #Gera pontos os quais definem um círculo na imagem
    
    radians = np.linspace(0, 2*np.pi, resolution)
    c = center[1] + radius*np.cos(radians) #polar co-ordinates
    r = center[0] + radius*np.sin(radians)
    
    return np.array([c, r]).T
# Exclude last point because a closed path should not have duplicate points
lin, col, prof = image.shape

if(col>lin):
    points = circle_points(int(lin/2), [lin*0.35, col/2], lin/2)[:-1]

else:
    points = circle_points(int(col/2), [lin*0.45, col/2], col/2)[:-1]

#SNAKE

snake = seg.active_contour(binary_sauvola,points,alpha=0.9,beta=0.05, gamma=0.5, w_line=0.5, w_edge=0.5)

# fig, ax = image_show2(binary_sauvola)
# ax.plot(points[:, 0], points[:, 1], '--r', lw=3)
# ax.plot(snake[:, 0], snake[:, 1], '-b', lw=3);

# =============================================================================
# CRIA MASCARA BINARIA DENTRO DA REGIAO DA SNAKE (0 -> FORA, 1-> DENTRO)

seg = np.zeros(binary_sauvola.shape,'bool')
l = snake[:,0].astype('int')
c = snake[:,1].astype('int')
 
seg[c,l] = 1

for l in range(lin): # ESSE FOR CRIA UMA BORDA, POIS EM ALGUNS CASOS A SNAJE ULTRAPASSA A BORDA E A MASCARA BINARIA NAO CONSIDERA COMO REGIAO FECHADA
    for c in range(col):
        if l==0 or c==0 or l==lin or c==col:
            seg[l,c]=1

seg = mm.binary_dilation(seg, mm.disk(9)) # MASCARA BINARIA
seg = ndimage.binary_fill_holes(seg)

#plt.figure()
#plt.imshow(seg)

# =============================================================================
#CRIA UMA IMAGEM RGB, ONDE OS PIXELS COM 1 DA MASCARA BINARIA RECEBEM OS VALORES DA IMAGEM ORIGINAL

im2 = image.astype("uint8")

im2 = np.zeros(image.shape,'uint8')

for l in range(lin):
    for c in range(col):
        if seg[l,c] == 1:
            im2[l,c,0] = image[l,c,0]
            im2[l,c,1] = image[l,c,1]
            im2[l,c,2] = image[l,c,2]

#plt.figure()
#plt.imshow(im2)

# =============================================================================
#LIMIAR RGB QUE IDENTIFICA TONS DE PELE E SALVA EM UMA IMAGEM BINARIA im3
            
lin, col, prof = im2.shape

im3 = np.zeros((lin,col))

for l in range(lin):
    for c in range(col):
        R = im2[l,c,0]
        G = im2[l,c,1]
        B = im2[l,c,2]
        M = max([R, G, B])
        m = min([R, G, B])
        if R>60 and G>40 and B>20 and (M-m)> 5 and abs(R-G)> 5 and R>G and R>B:
            im3[l,c] = 1
            
# plt.figure()
# plt.imshow(im3)

# =============================================================================
#TRANSFORMANDO A IMAGEM BINARIA QUE CONTEM APEAS OS TONS DE PELE EM RGB, ONDE OS PIXELS EM 1 RECEBEM VALORES IDENTICOS A IMAGEM ORIGINAL                               
im4 = image.astype("uint8")

im4 = np.zeros(image.shape,'uint8')

for l in range(lin):
    for c in range(col):
        if im3[l,c] == 1:
            im4[l,c,0] = image[l,c,0]
            im4[l,c,1] = image[l,c,1]
            im4[l,c,2] = image[l,c,2]
            
# plt.figure()
# plt.imshow(im4)

plt.figure()
plt.subplot(241)
plt.xlabel('Original')
plt.imshow(image.astype('uint8'))
plt.subplot(242)
plt.xlabel('+ Contrast in Grayscale')
plt.imshow(imCONT.astype('uint8'),cmap='gray')
plt.subplot(243)
plt.xlabel('+ Sauvola Threshold')
plt.imshow(binary_sauvola.astype('bool'),cmap='gray')
plt.subplot(244)
plt.xlabel('+ Active Contour Segmentation')
plt.imshow(binary_sauvola.astype('bool'),cmap='gray')
plt.plot(points[:, 0], points[:, 1], '--r', lw=3)
plt.plot(snake[:, 0], snake[:, 1], '-b', lw=3);
plt.subplot(245)
plt.xlabel('Segmentated Region')
plt.imshow(seg.astype('uint8'))
plt.subplot(246)
plt.xlabel('Cuted Region')
plt.imshow(im2.astype('uint8'))
plt.subplot(247)
plt.xlabel('+ Skin Tone RGB Threshold')
plt.imshow(im3, cmap="gray")
plt.subplot(248)
plt.xlabel('Final')
plt.imshow(im4.astype('uint8'))

