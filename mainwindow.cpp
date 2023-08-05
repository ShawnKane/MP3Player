#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);


    //background
    QPalette palette;
    QPixmap background(appDir + "/resource//background.png");
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    //stop btn
    ui->stopStartBTN->setStyleSheet("background-color: transparent; border: none;");
    QPixmap btnStopIcon(appDir + "/resource//play.png");
    ui->stopStartBTN->setIcon(btnStopIcon);

    //nextSoundBTN
    ui->nextSoundBTN->setStyleSheet("background-color: transparent; border: none;");
    QPixmap btnNextSoundIcon(appDir + "/resource//nexts.png");
    ui->nextSoundBTN->setIcon(btnNextSoundIcon);

    //predSoundBTN
    ui->predSoundBTN->setStyleSheet("background-color: transparent; border: none;");
    QPixmap btnPredSoundIcon(appDir + "/resource//preds.png");
    ui->predSoundBTN->setIcon(btnPredSoundIcon);

    //cursor
    QPixmap cursorPixmap(appDir + "/resource//cursor.png");
    QCursor cursor(cursorPixmap);
    this->setCursor(cursor);

    //slider volume and audio

    QFile styleVolumeSlider(appDir+"/slider.qss"); // Шлях до вашого файлу стилів
    styleVolumeSlider.open(QFile::ReadOnly);
    QString styleVolume = QLatin1String(styleVolumeSlider.readAll());

    QFile styleSoundSlider(appDir+"/soundSlider.qss"); // Шлях до вашого файлу стилів
    styleSoundSlider.open(QFile::ReadOnly);
    QString styleSound = QLatin1String(styleSoundSlider.readAll());

    ui->volumeSlider->setStyleSheet(styleVolume);
    ui->soundSlider->setStyleSheet(styleSound);

    // instantiate player and audio output
    // створення екземпляру плеєра та аудіовиходу
    M_Player = new QMediaPlayer();
    audioOutput = new QAudioOutput;
    Playlist playlist;
    M_Player->setAudioOutput(audioOutput);

    //tracking song status, slider position and changing its slider, sound settings
    //відслідковування стану пісні, позиції слайдері та зміна його ползунка, налаштування звуку
    connect(M_Player, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::mediaStatusChanged);
    connect(M_Player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    float volume = static_cast<float>(ui->volumeSlider->value()) / 100.0f;
    audioOutput->setVolume(volume);

    // audio length tracking
    // відслідковування довжини аудіо
    connect(M_Player,&QMediaPlayer::durationChanged,this,&MainWindow::durationChanged);
    connect(M_Player,&QMediaPlayer::positionChanged,this,&MainWindow::positionChanged);
    ui->soundSlider->setRange(0,M_Player->duration()/1000);

    //processing data sent from other instances of the program
    //обробка відправлень даних з інших екземплярів програми
    QtSingleApplication *app = qobject_cast<QtSingleApplication*>(QApplication::instance());
    if (app) {
        QObject::connect(app, &QtSingleApplication::messageReceived, this, &MainWindow::handleCommandLineArgs, Qt::UniqueConnection);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

//adding audio to a playlist
//додавання аудіо в плейлист
void MainWindow::addMediainPlaylist(QString url)
{
    playlist.addMedia(url);
}

//receiving a playlist
//получання плейлиста
Playlist MainWindow::getPlaylist()
{
    return playlist;
}


//audio playback
//відтворення аудіо
void MainWindow::PlayAudio(Playlist playlist, MainWindow::AudioPlayStatus status)
{

    QString FileName;
    //using AudioPlayStatus loading the correct audio
    //використовуючи AudioPlayStatus підгрузка правильного аудіо
    switch(status)
    {
    case THISorMAIN:
        FileName  = playlist.getThisMedia();
        break;
    case NEXT:
        FileName  = playlist.getNextMedia();
        break;
    case PRED:
        FileName  = playlist.getPredMedia();
        break;
    }

    //loading audio into the player, changing the text to its name, playing the audio
    //change statuses and buttons

    //завантаження аудіо в плеєр, зміна тексту на його назву, відтворення аудіо
    //зміна статусів та кнопки
    M_Player->setSource(QUrl::fromLocalFile(""));
    M_Player->setSource(QUrl::fromLocalFile(FileName));
    QFileInfo File(FileName);
    ui->nameSoundLB->setText(File.fileName());
    M_Player->play();
    playing = true;
    fileUpload = true;
    QPixmap btnStopIcon(appDir + "/resource//pause.png");
    ui->stopStartBTN->setIcon(btnStopIcon);
}

//receiving data from another instance of the program
//прийом даних з іншого екземпляру програми
void MainWindow::handleCommandLineArgs(const QString &args)
{
    if (!args.isEmpty()) {
        //QTextStream(stdout)<<"args :"<<args<<" - args end"<<Qt::endl;
        playlist.addMedia(args);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_F && !processing)
    {
        ui->nameSoundLB->setText("Кохаю Карінку!");
    }
    else
    {
        QMainWindow::keyPressEvent(event);
    }
}


//determining the length of the song, setting the slider to the maximum value
//визначення довжини пісні, встановлення слайдеру макс значення
void MainWindow::durationChanged(qint64 duration)
{
    Mduration = duration/1000;
    ui->soundSlider->setMaximum(Mduration);
}

//changing the point on the slider while the audio is playing
//зміна точки на слайдері поки аудіо відтворюється
void MainWindow::positionChanged(qint64 progress)
{
    if(!ui->soundSlider->isSliderDown())
    {
        ui->soundSlider->setValue(progress/1000);
    }
    updateDuration(progress/1000);
}

//change current and total time during playback
//зміна поточного та загального  часу під час відтворення
void MainWindow::updateDuration(qint64 duration)
{
    QString timestr;
    if(duration||Mduration)
    {
        QTime CurrentTime((duration/3600)%60,(duration/60)%60,duration%60,(duration*1000)%1000);
        QTime totalTime((Mduration/3600)%60,(Mduration/60)%60,Mduration%60,(Mduration*1000)%1000);
        QString format = "mm:ss";
        if(Mduration > 3600)
        {
            format="hh::mm::ss";
        }
        ui->currentTime->setText(CurrentTime.toString(format));
        ui->totalTime->setText(totalTime.toString(format));
    }
}

//pause and start audio
//пауза та старт аудіо
void MainWindow::on_stopStartBTN_clicked()
{

    //when audio is loaded and audio is (not)playing -> stop audio and change button
    //коли аудіо завантажене та аудіо (не)відтворюється -> зупинити аудіо та змінити кнопку
    if(fileUpload)
    {
        if(!playing)
        {
            M_Player->play();
            playing = true;
            QPixmap btnPlayIcon(appDir + "/resource//pause.png");
            ui->stopStartBTN->setIcon(btnPlayIcon);
        }
        else
        {
            QPixmap btnStopIcon(appDir + "/resource//play.png");
            ui->stopStartBTN->setIcon(btnStopIcon);
            M_Player->pause();
            playing = false;
        }
    }

}

//next audio
//наступне аудіо
void MainWindow::on_nextSoundBTN_clicked()
{
    if(fileUpload)
    {
        AudioPlayStatus nx;
        nx = NEXT;
        PlayAudio(playlist, nx);
    }
}

//previous audio
//минули аудіо
void MainWindow::on_predSoundBTN_clicked()
{
    if(fileUpload)
    {
        AudioPlayStatus nx;
        nx = PRED;
        PlayAudio(playlist, nx);
    }

}

//opening audio through explorer
//відкриття аудіо через провідник
void MainWindow::on_actionOpen_triggered()
{
    QStringList FileNames = QFileDialog::getOpenFileNames(this,tr("Select Audio File"),"",tr(""));


    if(!FileNames.isEmpty())
    {

        for(QString FileName : FileNames)
        {
            playlist.addMedia(FileName);
        }


        AudioPlayStatus nx;
        nx = THISorMAIN;
        PlayAudio(playlist, nx);
    }

}

//volume change
//зміна гучності
void MainWindow::on_volumeSlider_valueChanged(int value)
{
    float volume = static_cast<float>(value) / 100.0f;
    audioOutput->setVolume(volume);
}


void MainWindow::on_soundSlider_valueChanged(int value)
{

}

//rewinding the song when rewinding the slider manually
//перемотка пісні при перемотці слайдера вручну
void MainWindow::on_soundSlider_sliderMoved(int position)
{
    M_Player->setPosition(position * 1000);
}

//changing the track when it ends
//зміна треку коли він закінчиться
void MainWindow::mediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if (status == QMediaPlayer::EndOfMedia)
    {
        on_nextSoundBTN_clicked();
    }
}

