QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Filters.h \
    Image_Class.h \
    global.h \
    mainwindow.h \
    stb_image.h \
    stb_image_write.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    photo/House.bmp \
    photo/Wano 2.jpg \
    photo/Water 7.jpg \
    photo/arrow.jpg \
    photo/background.jpg \
    photo/background2.jpg \
    photo/building.jpg \
    photo/fruit.bmp \
    photo/gamma_adjusted_image.jpg \
    photo/infrared_image.jpg \
    photo/luffy.jpg \
    photo/mario.bmp \
    photo/mario.jpg \
    photo/name.jpg \
    photo/night3.jpg \
    photo/old_tv_image.jpg \
    photo/parots.bmp \
    photo/photographer.bmp \
    photo/purple_imageLuffy.jpg \
    photo/purple_imagewano.jpg \
    photo/samurai.jpg \
    photo/toy1.jpg \
    photo/toy2.jpg \
    photo/٢٠١٨٠١٢٠_١٢٢١١٠.jpg
