 // Main file that calls time simulation function 
 // Written by Paul Ologeh
 #include"simulation.h"
 #include<cstdio>
 #include<cstdlib>
 #include<iostream>
 using namespace std;
 
 int main()
 {
 	simulation Asim;  // creates type of class simulation
 	
 	cout<<"Welcome to ACSE Pizza "<<endl;
 	cout<<"This program simulates orders from our customers for 30 minutes"<<endl;
 	cout<<"The program will start now. Cheers \n\n"<<endl;	 
	Asim.simulateTime();  // calls simulation function
	  	
 	return 0;
 }