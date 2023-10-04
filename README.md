# README

Course: ENGR151 2021 Fall

Language: C++

Date: 2021.12.15

## Contributors

Pgroup-05:

- LiuQijia: 521370910165
- HuangJiahe: 521370910102
- LiLeyao: 521370910122
- PanYuheng: 521370910075



## Contents

1. Introduction
2. Instructions
3. Bonus
4. Individual contribution
7. Afterthoughts

*Other detailed information is in the wiki.*



### Introduction

In this project, we simulated an interstellar parking lot with C++ and OpenGL. 

In Parkinglot management system, we simulated a parkinglot with timing and ticketing system which can 

- Create a parking lot with many floors--each floor has different slots.
- Check whether there is an empty slot before each vehicle enters.
- Welcome the vehicle that enters the parkinglot.
- Count the time that a car stays in the parkinglot.
- Say goodbye to the vehicle and shows the fee according to the parking time.

In Interstellar parkinglot animation, we draw the parking lot  with the help of OpenGL with the following features

- Four kinds of interstellar vehicles will enter the parkinglot:

Teleported: have reserved slots marked by a rectangle randomly changing color and number of sides;
UFO: device that spins on itself;
Spacecraft(Rocket): vehicle which continuously zooms in and out;
Car: regular car with a small flag moving up and down;

- A parking lot, whose number of slots can be determined by the user.
- An animation that the vehicle stops at the barrier, the barrier opens and the vehicle enters its slot following a smooth trajectory.



### Instructions

#### How to use

Please use the makefile to compile

To animate the parkinglot management system, enter ./pms (or click on pms.exe) to launch, wait and see the vehicles coming in and out.

To animate the interstellar parkinglot animation,  enter ./ipa (or click on ipa.exe) to launch, then enter the number of slots in the user interface.

*Notice: the input should be an odd number that is larger than 24.*



### Bonus

1. Add a small flag moving up and down at the back of the car (Bonus 2)
2. Use Singleton to avoid lengthy functions that continuously creates and destroys objects (Bonus 3)
3. The polygon teleporter changes number of sides over time. (Bonus 4)



### Individual contribution

#### details are in the Changelog file

##### Parkinglot management system

- LiuQijia: Implementation of the cars; Ticket system.
- HuangJiahe: Implementation of the cars; Parkinglot regulation.

##### Interstellar parkinglot animation

- LiuQijia: Figures, Coloredfig and Vehicles class definition and implementation; Car and teleported animation; Trajectory of the cars;Implementation of the final process; Parkinglot zoom;
- HuangJiahe: Vec related definition and implementation; UFO animation; singleton creation; simple adjustments.
- LiLeyao: Parkinglot animation; Bug fixing; Format adjusting.
- PanYuheng:  Spacecraft animation; Parkinglot pole animation; Readme; Changelog; Bug fixing.



### Afterthoughts

- PanYuheng: Group work takes effort. But it feels great to be supported by teammates.
- HuangJiahe: The whole group cooperation process is complex but full of charm, we benefited from the orderly division of labor.
- LiuQijia: The use of OpenGL makes the whole process difficult to dubug......, but it is really fulfilling to see the vehicles made from points to run and rotate! Thanks a lot to my group members! They are the best!!