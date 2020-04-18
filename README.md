# ACSEPIZZA
This simulates Pizza orders sent to the Automatic and Control Systems Engineering Department Pizza Place. The Pizza orders can be simulated by the program or entered manually by the user. It calculates how much time it takes to prepare the order and tells when it would be ready given a queue of orders and only two pizza ovens. 

![alt text](https://github.com/paulologeh/ACSEPIZZA/blob/master/readme.png)

## Setup
### Mac/Linux
1. Install the GNU C++ Compiler using yum or apt or homebrew installer you use
```bash
sudo apt install gcc
```
2. Open up a terminal. If you have a mac (bash/zsh) will be the default terminal shell. Navigate to your desired directory and clone the repository. You can also download and unzip the repository.
```bash
git clone https://github.com/paulologeh/ACSEPIZZA.git
```
### Windows
1. Download @https://www.cygwin.com and select gcc, g++ etc and install.
2. Open up PowerShell or command prompt. Navigate to your desired directory and clone the repository. You can also download and unzip the repository.
```batch
git clone https://github.com/paulologeh/ACSEPIZZA.git
```
## Usage
### Mac/Linux
1. Run program in terminal
```bash
./run.sh
```
### Windows
1. Open run.bat or run in powershell/command prompt
```batch
run.bat
```

## Simulation Details

The ACSE Pizza company sells pizzas which are assembled by human operators who add toppings to a pizza base as it moves along a conveyor belt. There are 9 toppings available, one of which is pizza sauce. 
An operator will add a measured amount of a topping, which is the correct amount to be used on a 10” pizza. The ACSE Pizza company sells 10” pizzas, and no other size.  
A human operator prepares the pizza base and puts it onto a pizza conveyor belt. The ACSE Pizza company has two conveyor belts: one is to be used only for vegetarian pizzas, and the other is to be used only for pizzas that contain meat, poultry or fish. Once the pizza base is on the conveyor belt, it is first topped with pizza sauce. Following the sauce, as the pizza A human operator prepares the pizza base and puts it onto a pizza conveyor belt.

Example Suppose a pizza order starts at second 10. 
The operator is notified, then prepares the base (30 seconds). The customer is asked to choose toppings (30 seconds). She chooses 5 vegetarian toppings and pizza sauce (the 6th topping) is required, so the toppings will take 30 seconds to add to the pizza. The pizza is placed on the vegetarian conveyer belt, and is due to go into the vegetarian oven at second 100, and due to be finished at second 280. Suppose a second pizza order starts at second 30. The operator is notified, then prepares the base (30 seconds). The customer is asked to choose toppings (30 seconds). He chooses 3 vegetarian toppings and pizza sauce (the 4th topping) is required, so the toppings will take 20 seconds to add to the pizza. The pizza is placed on the vegetarian conveyor belt, and is due to go into the vegetarian oven at second 110 and finished at second 290. However, the vegetarian oven will not be available until second 280, so the time at which the second pizza goes into the oven must be changed to 280, and its finish time changed to 460. Any pizzas following in the vegetarian queue will also be delayed.
