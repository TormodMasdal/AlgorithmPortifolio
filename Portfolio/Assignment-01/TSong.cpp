#include "TSong.h"

// Initialize all the attributes when an instance of the class is created
TSong::TSong(std::string aArtist,
    std::string aTitle,
    std::string aYear,
    std::string aGenre,
    std::string aSource) : artist(std::move(aArtist)), title(std::move(aTitle)),
    year(std::move(aYear)), genre(std::move(aGenre)), source(std::move(aSource)){}

std::string TSong::GetArtist() {
    return artist;
}

std::string TSong::GetGenre() {
    return genre;
}

std::string TSong::GetSource() {
    return source;
}

std::string TSong::GetTitle() {
    return title;
}

std::string TSong::GetYear() {
    return year;
}





