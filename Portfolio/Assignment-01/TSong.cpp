#include "TSong.h"

#include <limits>
#include <string>

#include "TLinkedList.hpp"
#include "TQueue.hpp"
#include "TStack.hpp"

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

void TSong::PrintSong(TSong* aSong) {

    if (aSong == nullptr) {
        std::cout << "Found no song" << std::endl;
        return;
    }
    std::cout << "  Artist: " << aSong->GetArtist() << "\n";
    std::cout << "  Title: " << aSong->GetTitle() << "\n";
    std::cout << "  Year: " << aSong->GetYear() << "\n";
    std::cout << "  Genre: " << aSong->GetGenre() << "\n";
    std::cout << "  Source: " << aSong->GetSource() << "\n\n";
}

TSong* TSong::PlayNextSong() {
    // If the wish queue has data dequeue from the wishlist
    if (!WishQueue->IsEmpty()) {
        TSong* song = WishQueue->Dequeue();
        return song;
    }
    // If the wishlist is empty play from the main queue
    TSong* song = MainQueue->Dequeue();
    return song;
}

TSong* TSong::UserAddSong() {
    std::cout << "Please enter name of the song you wish to play (exactly as listed in the library): ";
    std::string songName;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, songName);

    // The library is rather short, therefore use a linear search
    auto* temp = songLibrary->GetHead()->GetNextPtr();
    while (temp->GetData()->GetTitle() != songName) {
        temp = temp->GetNextPtr();
    }
    return temp->GetData();
}

void TSong::ViewHistory() {
    if (HistoryStack->GetItemAmount() == 0) {
        std::cout << "No songs finished played yet" << std::endl;
        return;
    };
    for (int i = 0; i < HistoryStack->GetItemAmount(); i++) {
        if (TSong* song = HistoryStack->GetArray(i); song != nullptr) {
            std::cout << "Artist: " << song->GetArtist() << "\n";
            std::cout << "Title: "  << song->GetTitle()  << "\n";
            std::cout << "Year: "   << song->GetYear()   << "\n";
            std::cout << "Genre: "  << song->GetGenre()  << "\n";
            std::cout << "Source: " << song->GetSource() << "\n\n";
        }
    }
}

void TSong::PlayPreviousSong() {
    // Peeks the previous song
    TSong* song = HistoryStack->Peek();

    // Adds the previous song to the front of the list
    WishQueue->FrontOfQueue(song);
}





