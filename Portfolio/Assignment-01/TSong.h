//
// Created by tormo on 11/3/2025.
//

#ifndef TSONG_H
#define TSONG_H
#include "iostream"

class TSong {

public:
    // Constructor
    TSong(std::string aArtist,
    std::string aTitle,
    std::string aYear,
    std::string aGenre,
    std::string aSource);

    // Getters for the private attributes
    std::string GetArtist();
    std::string GetTitle();
    std::string GetYear();
    std::string GetGenre();
    std::string GetSource();

    static void PrintSong(TSong* aSong);
    static TSong* PlayNextSong();
    static TSong* UserAddSong();
    static void ViewHistory(); // View all songs listened to
    static void PlayPreviousSong(); // Puts previous song to front of wish queue

private:
    std::string artist;
    std::string title;
    std::string year;
    std::string genre;
    std::string source;
};



#endif //TSONG_H
