#-------------------------------------------------
#
# Project created by QtCreator 2019-12-08T12:52:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HospitalSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        appointment.cpp \
        doctor.cpp \
        doctor_card.cpp \
        doctors_page.cpp \
        emergencypatient.cpp \
        hospital_system_manager.cpp \
        main.cpp \
        mainwindow.cpp \
        patient.cpp \
        patient_card.cpp \
        patients_page.cpp \
        person.cpp \
        room.cpp \
        welcome_page_frame.cpp

HEADERS += \
        appointment.h \
        doctor.h \
        doctor_card.h \
        doctors_page.h \
        emergencypatient.h \
        hospital_system_manager.h \
        mainwindow.h \
        patient.h \
        patient_card.h \
        patients_page.h \
        person.h \
        room.h \
        welcome_page_frame.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    displayImage.jpg
