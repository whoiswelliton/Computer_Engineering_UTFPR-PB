import tensorflow as tf
from skimage import io, transform
from tensorflow.keras import layers, models, regularizers
import matplotlib.pyplot as plt
import glob, os
import numpy as np

os.listdir()

arqs = glob.glob(os.curdir + '/im*')
arqs.sort()
train_images = np.zeros((53*4, 240, 320, 3))
test_images = np.zeros((53, 240, 320, 3))
train_labels = np.zeros((53*4, 1))
test_labels = np.zeros((53, 1))

x = 1
id_treina = 0
for i in range(len(arqs)):
    if ((i+1)%5)==0:
        test_images[x-1,:,:,:] = io.imread(arqs[i])
        test_labels[x-1] = x-1
        x = x+1
    else:
        train_images[id_treina,:,:,:] = io.imread(arqs[i])
        train_labels[id_treina] = x-1
        id_treina += 1

# Normalize pixel values to be between 0 and 1
train_images, test_images = train_images / 255.0, test_images / 255.0

model = models.Sequential()

model.add(layers.experimental.preprocessing.RandomFlip("horizontal_and_vertical")) #novo
model.add(layers.experimental.preprocessing.RandomRotation(0.2)) #novo

model.add(layers.Conv2D(32, (3, 3), activation='relu', input_shape=(240, 320, 3))) #corrigido
model.add(layers.MaxPooling2D((2, 2)))
model.add(layers.Conv2D(64, (3, 3), activation='relu'))
model.add(layers.MaxPooling2D((2, 2)))
model.add(layers.Conv2D(64, (3, 3), activation='relu'))

model.add(layers.Dropout(0.5)) #novo

model.add(layers.Flatten())
model.add(layers.Dense(64, activation='relu', kernel_regularizer=regularizers.l2(0.001))) #adicionado regularizacao
model.add(layers.Dense(53)) #corrigido



model.compile(optimizer='adam',
              loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
              metrics=['accuracy'])

history = model.fit(train_images, train_labels, epochs=50, 
                    validation_data=(test_images, test_labels))

#print(model.summary())

plt.figure()
plt.plot(history.history['accuracy'], label='accuracy')
plt.plot(history.history['val_accuracy'], label = 'val_accuracy')
plt.xlabel('Epoch')
plt.ylabel('Accuracy')
plt.ylim([0.5, 1])
plt.legend(loc='lower right')

test_loss, test_acc = model.evaluate(test_images,  test_labels, verbose=2)

print(test_acc)