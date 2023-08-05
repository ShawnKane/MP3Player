#ifndef PLAYLIST_H
#include<iostream>
#include<QString>
#include<QStringList>
#define PLAYLIST_H

class Playlist
{
public:
    Playlist();
    void addMedia(const QString &filePath);
    QString getThisMedia();
    QString getNextMedia();
    QString getPredMedia();

private:
    QStringList mediaList;
    int currentIndex;
    int *ptrCurrentIndex = &currentIndex;
};

#endif // PLAYLIST_H
