#include "menu.h"
#include "iostream"
#include "TLinkedList.h"
#include "TQueue.h"
#include "TStack.h"



void RunMenu() {
    int choice;
    TSong* currentlyPlaying = nullptr;
    TNode<TSong>* navigator = songLibrary->GetHead();

    while (true) {
        std::cout
        << "------------------------------------------------------------\n"
        << "| WELCOME TO THE CONSOLE MUSIC PLAYER!                     |\n"
        << "|----------------------------------------------------------|\n"
        << "| HERE ARE THE DIFFERENT CONTROLS:                         |\n"
        << "| Press 1: Navigate forward in the library                 |\n"
        << "| Press 2: Navigate backwards in the library               |\n"
        << "| Press 3: Print entire library                            |\n"
        << "| Press 4: Add song to Main queue                          |\n"
        << "| Press 5: Add song to Wish queue                          |\n"
        << "| Press 6: Peek next song in Main queue                    |\n"
        << "| Press 7: Peek next song in Wish queue                    |\n"
        << "| Press 8: Play next song                                  |\n"
        << "| Press 9: See history of played songs                     |\n"
        << "| Press 10: Play previous song                             |\n"
        << "| Press 11: Currently playing song                         |\n"
        << "| Press 12: Exit program                                   |\n"
        << "------------------------------------------------------------" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                if (navigator != songLibrary->GetTail()) {
                    navigator = navigator->GetNextPtr();
                    TSong::PrintSong(navigator->GetData());
                }
                break;
            }
            case 2: {
                if (navigator != songLibrary->GetHead()){ navigator = navigator->GetPrevPtr(); }
                TSong::PrintSong(navigator->GetData());
                break;
            }
            case 3: songLibrary->PrintList();
                break;
            case 4: {
                TSong* mainSong = TQueue<TSong>::UserAddSong();
                MainQueue->Enqueue(mainSong);
                break;
            }
            case 5: {
                TSong* wishSong = TQueue<TSong>::UserAddSong();
                WishQueue->Enqueue(wishSong);
                break;
            }
            case 6: {
                TSong* MainQueuePeek = MainQueue->Peek();
                TSong::PrintSong(MainQueuePeek);
                break;
            }
            case 7: {
                TSong* WishQueuePeek = WishQueue->Peek();
                TSong::PrintSong(WishQueuePeek);
                break;
            }
            case 8: {
                // Only add the song to history stack when we change the song
                if (currentlyPlaying != nullptr){ HistoryStack->Push(currentlyPlaying); HistoryStack; }
                currentlyPlaying = TQueue<TSong>::PlayNextSong();
                break;
            }
            case 9: {
                TStack<TSong>::ViewHistory();
                break;
            }
            case 10: {
                if (currentlyPlaying != nullptr){ HistoryStack->Push(currentlyPlaying); HistoryStack; }
                currentlyPlaying = TStack<TSong>::PlayPreviousSong();
                break;
            }
            case 11: TSong::PrintSong(currentlyPlaying);
                break;
            case 12: return;
            default: std::cout << "Wrong input" << std::endl;
                break;
        }
    }
}
