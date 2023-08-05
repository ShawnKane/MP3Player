#include "main.h"

int main(int argc, char *argv[])
{
    QtSingleApplication a(argc,argv);


    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "mp3Player_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    //if there is already an instance of the program, then process the other's data and
    //send it to the first
    //якщо вже є екземпляр програми тоді обробити дані іншого і відправити в перший
    if(a.isRunning())
    {

        if(argc > 1)
        {
            QStringList arguments;
            for (int i = 1; i < argc; ++i) {
                arguments.append(QString::fromLocal8Bit(argv[i]));
            }

            QString argumentsString = arguments.join(" ");
            a.sendMessage(argumentsString);
        }
        return 0;
    }
    //if not, then just instantiate the app, process and pass the value
    //якщо ні, тоді просто створити екземпляр програми, обробити та передати значення
    else
    {
        MainWindow w;

        //std::cout<<"else "<<argc<<*argv;

        if (argc > 1)
        {

            for (int i = 1; i < argc; ++i) {
                //std::string url(argv[i]);
                QString url = QString::fromLocal8Bit(argv[i]);
                //std::cout<<argv[i];
                w.addMediainPlaylist(url);
            }
            MainWindow::AudioPlayStatus status = MainWindow::THISorMAIN;
            w.PlayAudio(w.getPlaylist(),status);

        }

        w.show();
        return a.exec();
    }
}



