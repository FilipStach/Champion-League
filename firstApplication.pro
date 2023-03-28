QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Ball.cpp \
    ChampionsLeague.cpp \
    Club.cpp \
    ClubsContainer.cpp \
    Coach.cpp \
    CoachesContainer.cpp \
    Defender.cpp \
    FileReader.cpp \
    Footballer.cpp \
    GoalKeeper.cpp \
    HeaderAbility.cpp \
    Match.cpp \
    Midfielder.cpp \
    MyClub.cpp \
    PassingAbility.cpp \
    PlayersContainer.cpp \
    ShootingAbility.cpp \
    Striker.cpp \
    TackleAbility.cpp \
    TransferWindow.cpp \
    WeatherStation.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Ball.h \
    ChampionsLeague.h \
    Club.h \
    ClubsContainer.h \
    Coach.h \
    CoachesContainer.h \
    Defender.h \
    FileReader.h \
    Footballer.h \
    GoalKeeper.h \
    HeaderAbility.h \
    Match.h \
    Midfielder.h \
    MyClub.h \
    PassingAbility.h \
    PlayersContainer.h \
    ShootingAbility.h \
    Striker.h \
    TackleAbility.h \
    TransferWindow.h \
    WeatherStation.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
