QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    basesqlmodel.cpp \
    buywindow.cpp \
    main.cpp \
    mainwindow.cpp \
    qpart.cpp \
    qpartslistmodel.cpp \
    qpartslistsqlmodel.cpp \
    qpartssqlmodel.cpp

HEADERS += \
    BaseTableObject.h \
    QBaseTableSqlModel.h \
    basesqlmodel.h \
    buywindow.h \
    mainwindow.h \
    qpart.h \
    qpartslistmodel.h \
    qpartslistsqlmodel.h \
    qpartssqlmodel.h \
    singleton.h

FORMS += \
    buywindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qrc.qrc
