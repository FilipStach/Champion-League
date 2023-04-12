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
    MenagerWindow.cpp \
    Midfielder.cpp \
    MyClub.cpp \
    PassingAbility.cpp \
    PlayersContainer.cpp \
    ResultWindow.cpp \
    ShootingAbility.cpp \
    Striker.cpp \
    TackleAbility.cpp \
    TournamentCreationWindow.cpp \
    TrainingWindow.cpp \
    TransferDialog.cpp \
    TransferWindow.cpp \
    UpdateLineupWindow.cpp \
    WeatherStation.cpp \
    main.cpp

HEADERS += \
    Ball.h \
    ChampionsLeague.h \
    Club.h \
    ClubsContainer.h \
    Coach.h \
    CoachesContainer.h \
    Container.h \
    Defender.h \
    FileReader.h \
    Footballer.h \
    GoalKeeper.h \
    HeaderAbility.h \
    Match.h \
    MenagerWindow.h \
    Midfielder.h \
    MyClub.h \
    PassingAbility.h \
    PlayersContainer.h \
    ResultWindow.h \
    ShootingAbility.h \
    Striker.h \
    TackleAbility.h \
    TournamentCreationWindow.h \
    TrainingWindow.h \
    TransferDialog.h \
    TransferWindow.h \
    UpdateLineupWindow.h \
    WeatherStation.h

FORMS += \
    MenagerWindow.ui \
    ResultWindow.ui \
    TournamentCreationWindow.ui \
    TrainingWindow.ui \
    TransferDialog.ui \
    UpdateLineupWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    BackGround.qrc \
    Fonts.qrc
