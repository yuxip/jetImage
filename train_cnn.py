import keras
from keras.models import Sequential
from keras.layers import Dense, Dropout, Flatten
from keras.layers import Conv2D, MaxPooling2D, SpatialDropout2D 
from keras import backend as K

from sklearn.model_selection import train_test_split
import numpy as np

from processEvent import readJetImages

def train_validate():

    batch_size = 64
    num_classes = 2
    epochs = 10

    # image dimensions
    img_rows, img_cols = 33, 33

    jetImages_g, jetImages_q = readJetImages()
    y_g = np.array([0]*jetImages_g.shape[0])
    y_q = np.array([1]*jetImages_q.shape[0])


    X_all = np.vstack((jetImages_g, jetImages_q))
    y_all = np.append(y_g, y_q)
    print 'X_all.shape:'
    print X_all.shape
    print 'y_all.shape:'
    print y_all.shape
    print '\n'

    X_train, X_test, y_train, y_test = train_test_split(X_all, y_all, test_size=0.2, random_state=42, shuffle=True, stratify=y_all)
    print 'X_train.shape:'
    print X_train.shape
    print 'y_train.shape:'
    print y_train.shape
    print '\n'
    
    print 'X_test.shape:'
    print X_test.shape
    print 'y_test.shape:'
    print y_test.shape
    print '\n'
    
    X_train = X_train.astype('float32')
    X_test  = X_test.astype('float32')
    y_train = keras.utils.to_categorical(y_train, num_classes)
    y_test  = keras.utils.to_categorical(y_test, num_classes)
    input_shape = (3, img_rows, img_cols) # channel first

    # define the CNN model
    model = Sequential()
    model.add(Conv2D(64, kernel_size=(8, 8), activation='relu', 
              input_shape=input_shape, data_format="channels_first",
              kernel_initializer="he_normal"))
    model.add(MaxPooling2D(pool_size=(2, 2), strides=2))
    model.add(SpatialDropout2D(0.25))
    model.add(Conv2D(64, kernel_size=(4, 4), activation='relu', kernel_initializer="he_normal"))
    model.add(MaxPooling2D(pool_size=(2, 2), strides=2))
    model.add(SpatialDropout2D(0.5))
    model.add(Conv2D(64, kernel_size=(4, 4), activation='relu', kernel_initializer="he_normal"))
    model.add(MaxPooling2D(pool_size=(2, 2), strides=2))
    model.add(SpatialDropout2D(0.5))
    model.add(Flatten())
    model.add(Dense(128, activation='relu', kernel_initializer="he_normal"))
    model.add(Dropout(0.5))
    model.add(Dense(num_classes, activation='softmax', kernel_initializer="he_normal"))

    model.compile(loss=keras.losses.categorical_crossentropy,
                  optimizer=keras.optimizers.Adadelta(),
                  metrics=['accuracy'])

    model.fit(X_train, y_train,
              batch_size=batch_size,
              epochs=epochs,
              verbose=1,
              validation_data=(X_test, y_test))

    score = model.evaluate(X_test, y_test, verbose=0)
    print('Test loss:', score[0])
    print('Test accuracy:', score[1])
    

if __name__ == '__main__':
    train_validate()
