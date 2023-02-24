//Jackie Lin 
//COP4520 - CONCEPTS PARALLEL DISTRIBUTED
// 02/22/2023

#include <iostream>
#include <array>
#include <deque>
#include <chrono>
#include <time.h>
#include <mutex>
#include <unordered_set>
#include <random>

//for out thread
#include <thread>

//concrete number of guests
#define GUEST_NUM 100

//Sign on door stsatus
enum Sign {
    AVAILABLE,
    BUSY
};

//Tracks guests who seen case
std::unordered_set<std::thread::id> guestsVisited{};
std::mutex mutex;

//decalre showrooom status, which is initalized to Available from start
Sign showRoomStatus = Sign::AVAILABLE;

//function prototype
void seeVase(int threadInd); 
int randNum(int min, int max);


int main() {
    //start of our timer 
    //double start = clock();
    auto start = std::chrono::high_resolution_clock::now();

    //declare our threads
    std::array<std::thread, GUEST_NUM> threads{};

    //let threads(guests) see vase using method 2
    for(int i = 0; i < threads.size(); i++) {
        threads[i] = std::thread(seeVase, i);
    }

    //join our threads
    for(int i = 0; i < GUEST_NUM; i++) {
		threads[i].join();
	}


    //end of our timer
    //double end = clock();
    auto end = std::chrono::high_resolution_clock::now();

    //total time to run threads
	//double time = (end - start);
    auto time = std::chrono::duration<double, std::milli>(end - start);
    
    std::cout << std::endl;
    std::cout << "Total count of guests who viewed the Minotar's crystal vase." << std::endl;
    std::cout << "Time: " << time.count() << "ms" << std::endl;
}

//current thread(guest) is sent to view vase
void seeVase(int threadInd){
    //set current thread(guest) 
    std::thread::id threadId = std::this_thread::get_id();

    //number of guest who seen vase is tracked
    while(guestsVisited.size() < GUEST_NUM){
        mutex.lock();
        //lock

        //check if room show room is avaible and whehter or not that guest has already seen the vase
        if(showRoomStatus == Sign::AVAILABLE && guestsVisited.find(threadId) == guestsVisited.end()){
            //current thread(guest) will set show room sign to busy, so no one is to enter
            showRoomStatus = Sign::BUSY;
            
            std::cout << "Guest Number(" << threadInd << ") is viewing the Minotar's crystal vase" << std::endl;
            
            //(testing purposes of potential realistic viewing time frame)
            //delay thread time for how long the given guest is viewing the vase
            //std::this_thread::sleep_for(std::chrono::milliseconds(randNum(1000, 10000)));

            //current thread(guest) then sets singn to avaible and leaves show room after seeing case
            showRoomStatus = Sign::AVAILABLE;
            
            //set the current thread(guest) to have seen case
            guestsVisited.insert(threadId);
        }

        mutex.unlock();
        //unlock
    }
}

///generates random number num for guest to enter
int randNum(int min, int max){
	return rand() % (max - min + 1) + min;
}
//end of function
