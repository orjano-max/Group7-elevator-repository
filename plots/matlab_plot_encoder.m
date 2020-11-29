
%This program plots the values from the encoder when using "Serial.println()" 
%command inside interrupt function, and when having the "Serial.println()" command
%another place in the program.

clc; close all; clear all;

%This first plot is with the Serial.println() command inside the interrupt
%function

%Importing data copied from arduino serial monitor
counts1 = importdata('encoder, print in interrupt.txt');

%%Storing data in an array
C1 = counts1(:,1);

%Plotting the values
figure(1)
plot(C1)
title('Serial.println() inside interrupt function')
xlabel('Number of counts');
ylabel('Value')

%--------------------------------------------------------------------

%This second plot is with the Serial.println() command 
%outside the interrupt function

%Importing data copied from arduino serial monitor
counts2 = importdata('encoder, print outside interrupt.txt');

%Storing data in an array
C2 = counts2(:,1);

%Plotting the values
figure(2)
plot(C2)
title('Serial.println() outside interrupt function')
xlabel('Number of counts');
ylabel('Value')

