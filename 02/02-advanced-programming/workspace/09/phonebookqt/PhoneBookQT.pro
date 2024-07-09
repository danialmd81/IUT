QT       += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcontact.cpp \
    addnumber.cpp \
    changename.cpp \
    contact.cpp \
    deletephone.cpp \
    editcontact.cpp \
    editephonenum.cpp \
    editphonename.cpp \
    favorite.cpp \
    main.cpp \
    mainwindow.cpp \
    phoneBook.cpp \
    showcontactnum.cpp \
    showsorted.cpp

HEADERS += \
    addcontact.h \
    addnumber.h \
    changename.h \
    contact.h \
    deletephone.h \
    editcontact.h \
    editephonenum.h \
    editphonename.h \
    favorite.h \
    mainwindow.h \
    phoneBook.h \
    showcontactnum.h \
    showsorted.h

FORMS += \
    addcontact.ui \
    addnumber.ui \
    changename.ui \
    deletephone.ui \
    editcontact.ui \
    editephonenum.ui \
    editphonename.ui \
    favorite.ui \
    mainwindow.ui \
    showcontactnum.ui \
    showsorted.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
