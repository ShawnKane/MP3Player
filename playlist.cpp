#include "playlist.h"

Playlist::Playlist() : currentIndex(0) {}

//adding to the list of audio paths
//додавання в список шляхів до аудіо
void Playlist::addMedia(const QString &filePath) {
    mediaList.push_back(filePath);
}

//get the path to the current audio
//получити шлях до поточного аудіо
QString Playlist::getThisMedia()
{

    if (mediaList.isEmpty())
        return QString();
    QString thisMedia = mediaList.at(mediaList.size()-1);
    //std::cout<<currentIndex<<"    "<<mediaList.size()<<std::endl;
    return thisMedia;
}

//get path to next audio
//получити шлях до наступного аудіо
QString Playlist::getNextMedia() {
    if (mediaList.isEmpty())
        return QString();

    //if the audio is the last in the list -> return the first audio
    //якщо аудіо останнє в списку -> вернути перше аудіо
    if(currentIndex == mediaList.size()-1)
    {
        QString nextMedia = mediaList.at(0);
        *ptrCurrentIndex = 0;
        //std::cout<<currentIndex<<"  1  "<<mediaList.size()<<std::endl;
        return nextMedia;
    }

    QString nextMedia = mediaList.at(currentIndex+1);
    *ptrCurrentIndex = (currentIndex+1) % mediaList.size();
    //std::cout<<currentIndex<<"  2  "<<mediaList.size()<<std::endl;
    return nextMedia;
}
//get the path to the previous audio
//получити шлях до минулого аудіо
QString Playlist::getPredMedia() {
    if (mediaList.isEmpty())
        return QString();

    //if the current audio is the first in the list -> return the path to the last in the list
    //якщо поточне аудіо перше в списку -> вернути шлях до останнього у списку
    if(currentIndex==0)
    {
        QString predMedia= mediaList.at(mediaList.size()-1);
        *ptrCurrentIndex = mediaList.size()-1;
        std::cout<<currentIndex<<"    "<<mediaList.size()<<std::endl;
        return predMedia;

    }

    QString predMedia = mediaList.at(currentIndex-1);
    *ptrCurrentIndex = (currentIndex - 1) % mediaList.size();
    std::cout<<currentIndex<<"    "<<mediaList.size()<<std::endl;
    return predMedia;
}



