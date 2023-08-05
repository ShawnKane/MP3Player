#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QUrl>
#include<QFileDialog>
#include "playlist.h"
#include<QSoundEffect>
#include"main.h"
#include<QPalette>
#include<QPixmap>
#include<QCursor>
#include<qtsingleapplication.h>
#include<iostream>
#include<QDir>
#include<QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addMediainPlaylist(QString url);
    Playlist getPlaylist();
    enum AudioPlayStatus
    {
        THISorMAIN=0,
        NEXT=1,
        PRED=2,

    };
    void PlayAudio(Playlist playlist, AudioPlayStatus status);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *M_Player;
    QAudioOutput *audioOutput;
    Playlist playlist;
    qint64 Mduration;
    bool playing = false;
    bool fileUpload = false;
    bool processing = false;
    QString appDir = QCoreApplication::applicationDirPath();
    QPixmap btnPlayIcon;
    QPixmap btnStopIcon;
    void handleCommandLineArgs(const QString &args);
    void keyPressEvent(QKeyEvent *event) override;


protected:

private slots:
    void durationChanged(qint64 duration);
    void positionChanged(qint64 progress);
    void updateDuration(qint64 duration);
    void mediaStatusChanged(QMediaPlayer::MediaStatus status);
    void on_stopStartBTN_clicked();
    void on_nextSoundBTN_clicked();
    void on_predSoundBTN_clicked();
    void on_actionOpen_triggered();
    void on_volumeSlider_valueChanged(int value);
    void on_soundSlider_valueChanged(int value);
    void on_soundSlider_sliderMoved(int position);

};
#endif // MAINWINDOW_H
