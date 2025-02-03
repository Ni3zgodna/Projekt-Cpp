#include "matematyka.h"
#include "mainwindow.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <utility>

#include <QApplication>
#include <QMediaPlayer>
#include <QDebug>
#include <QAudioOutput>
#include <QUrl>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QMediaPlayer *mediaPlayer = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;

    mediaPlayer->setAudioOutput(audioOutput);

    QString musicFile = "qrc:/sounds/Muzyka.mp3";
    mediaPlayer->setSource(QUrl(musicFile));


    audioOutput->setVolume(10);
    mediaPlayer->setLoops(QMediaPlayer::Infinite);
    mediaPlayer->play();

    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();

    return 0;
}
