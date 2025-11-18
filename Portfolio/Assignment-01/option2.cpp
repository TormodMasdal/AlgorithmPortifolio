// Option 2 (Advanced): Console Music Player.


#include "option2.h"
#include "SharedLib.h"
#include "../SharedLib/TLinkedList.hpp"
#include "TSong.h"
#include "menu.h"




static bool SongReadCallback(const int aIndex, const int aTotalCount, const std::string& aArtist, const std::string& aTitle, const std::string& aYear, const std::string& aGenre, const std::string& aSource) {
	// Implement the logic to process each song read from the file
	// For example, print the song details to the console

	auto* song = new TSong(aArtist, aTitle, aYear, aGenre, aSource);

	// Populates the songLibrary
	songLibrary->Append(song);

	return true;
}


int RunApp() {

	const std::string filename = "C:/Users/tormo/IKT203Exam/IKT203Exam/DATA/songs.txt"; // Specify the path to the songs file
	ReadSongsFromFile(filename, SongReadCallback);

	RunMenu();
	return 0;
}