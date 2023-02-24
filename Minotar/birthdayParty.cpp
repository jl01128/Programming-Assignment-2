//Jackie Lin 
//COP4520 - CONCEPTS PARALLEL DISTRIBUTED
// 02/22/2023

#include <iostream>
#include <array>
#include <chrono>
#include <mutex>
#include <time.h>
#include <algorithm>
#include <random>

//for our thread
#include <thread>

#define GUEST_NUM 25

//Tracks the guests tthat have eaten cupacak in laybrinth
std::array<bool, GUEST_NUM> chosenGuests;
std::mutex mutex;

//checks if cupcake is present in laybrinth
bool cupcakePresent = true;

//tracks our number of guests
int counter = 0;

//Tracks the current guest in laybrinth
int currentThread;

//function prototype
void guestInLaybrinth(unsigned int threadInd);
void cupCakeChecker();
int randNum(int min, int max);

int main(){

    //start of our timer 
    //double start = clock();
    auto start = std::chrono::high_resolution_clock::now();

    //declare our threads for given number of guests
    std::array<std::thread, GUEST_NUM> threads{};

    
    //first thread sets up counter and checks if cupcake is present
    threads[0] = std::thread(cupCakeChecker);

    //set all threads(guest) to enter laybrinth
    for(int i = 1; i < threads.size(); i++) {
        threads[i] = std::thread(guestInLaybrinth, i);
    }


    //continue to generate number until all guest have entered laybrinth
    while(counter < GUEST_NUM) {
        currentThread = randNum(0, GUEST_NUM);
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
    std::cout << "Total count of guests who entered Laybrinth: " << counter << std::endl;
    std::cout << "Time: " << time.count() << "ms" << std::endl;

}

//guests enter laybrinth function call
void guestInLaybrinth(unsigned int threadInd) {
    
    //tracks the number of guests that have enter laybrinth
    while(counter < GUEST_NUM){
        //lock
        mutex.lock();

        //marks current thread to see if enter laybrinth and if cupcake present
        if(currentThread == threadInd && cupcakePresent && !chosenGuests[threadInd]) {
            cupcakePresent = false;
            //guest taken cupcake
            chosenGuests[threadInd] = true;
            //guest has enter laybrinth
            std::cout << "Guest Number(" << threadInd << ") entered laybrinth and ate the cupcake" << std::endl;
        }

        //unlock
        mutex.unlock();
    }
}
//end of function

//used by first thread set to count guest
void cupCakeChecker(){
    
    //keeps track of number guest number
    while(counter < GUEST_NUM) {
        mutex.lock();

        //start from first thread
        if(currentThread == 0){
           
            //cupcake not present, add to count and set new cupcake
            if(!cupcakePresent){
                counter++;
                //added new cupcake
                cupcakePresent = true;
            }
            
            //make sures that every given thread(guests has taken cupcake)
            //whihc we then add to count and set new cake
            if(cupcakePresent && !chosenGuests[0]){
                counter++;
                cupcakePresent = true;
                //added new cupcake
                chosenGuests[0] = true;
                // guest has taken cupcake
            }
        }
        //unlcok
        mutex.unlock();
    }
}
//end of cupcake checker in laybrinth

//generates random number num for guest to enter
int randNum(int min, int max) {
	return rand() % (max - min + 1) + min;
}
//end of function
