# Programming-Assignment-2
by Jackie Lin

To run the code:

1. First access the Minator Folder
2. Then type in the file name in the paratheneses section in the command below:
```
$ g++ -std=c++11 -pthread "nameOfFile".cpp
$ ./a.out
```

Set concerte numnber for N as GUEST_NUM

# 1. Minotaurs's Birthday Party 

Initial Attempt Issues:
 ```
*Threads were not able to successfuly run the problem in our desired time, as each of the number of guests threads weren't each handling their set inputs

*Set up problem that didn't follow the problem guidline, in terms of having no random instances on which guest go in(whether or not the have already been in or not. Which although produced a quick runtime, considering the threads prcoessed the functions in terms linear order in which each guest who hasn't been in the laybrinth, without letting guest who already been in, enter again when told by the Minotuar. 

*DUE to the randomnes of which guests go in, runtime is varied depending on the random numbers we get, whihc has praoduced a varied range of runtime complexity that range from less than 1 second to around 25 seconds(larger cases typically).

```

Solution and Efficiency
 ```
Set the correct thread instances based upon guests num, which produced the resonalbe runtime for both instances

Each thread is to eat one cupcake only and have the first thread act as our counter for cupcakes that were replaced.

Adhereed to the project guidlelines for randomn guest entry, which not followed the guidlines, but was still able to produce quick runtimes for better cases.

*DUE to how random we get our numbers, runtime is rather complex for far larger number of guests due to the large range of numbers to run through, yet has produced results in resonabke time(seconds) and even under 1 second for lucky cases. 
```


# 2. Minotaurs's Crystal Vase 

## Strategy 2


Initial Attempt Issues:
 ```
*Threads were not able to successfuly run the problem in our desired time, as each of the number of guests threads weren't each handling their set inputs

*Annoying syntax error in implemented the two cases of the sign in being avaible or busy, which resulted in several compilation error

```

Solution and Efficiency
 ```
Set the correct thread instances based upon guests num, which produced a fast runtime for both instances, which alwasy lead to a runtime to be less than 1 second.

Was able to implement a enum data type, that allowed me to adhere to the guidlines for strategy 2 and produce a succesful and fast reuslt. 

```

##Advantages and Disadvantages

#### Method 1
* Advantages:
  * Implementaion is easy in terms of threads, in which everyone can all simultanosly enter the castle
  * Easily able to implement a random function, to declarea make a random guest to see vase
* Disadvantages:
  * No guest will be guranteed to see the vase or know when they will see it eithier
  * Certain guest will get the chance to vase many times more than other guest who may or may not have seen the vase.
  * Time consuming in making sure everyone saw the vase within a reasonable time frame, as those who have already seen amy go back

#### Method 2
* Advantages:
  * Guests are able to know availabilty to enter the show room and not waste time to go there
  * Allows a greater opporutnity for allowing all guests the chance to see the vase
  * Guests will have the opporutnity to see the vase for as long as want, which means they won't proaobly go back again
* Disadvantages:
  * The time frame the guest viewing the vase are in the showroom will vary and might be long for certain individuals
  * Hard to adhere to a reasonable time frame for all guests to see the vase, as guest who seen the vase can some again and for larger numbers of guests.
  * Not 100% guranteed that everyone will see the vase
 

#### Method 3
* Advantages:
  * Easy implemntation of queue system for the guests to view the vase
  * Everyone gurantee to see the vase
  * greater chance for quick process for all guest to see vase, if time viewing the vase is also limited
  * Those who haven't seen vase will be prioritized first than those who already saw it.
* Disadvantages:
  * Majority of the advanatgescan only be fulfilled if everyone line up in queue from initial line up phase
  * Time limit in viewing the vase when in showroom, is not declared, so may be instances of guest being in there for long
