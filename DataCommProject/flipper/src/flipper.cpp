/*
*@author Shawn Button
*Reads bytes of data in and randomly flips bits
*/
#include "..\include\flipper.h"
#include <time.h>
#include <iostream>
#include <iterator>
#include <deque>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

//getMessage
deque<unsigned char> getMessage(){
    deque<unsigned char> result;
    char x;
    while(cin>>x){
        result.push_back(x);
    }
    return result;
}

//flipOrNoFlip
short flipOrNoFlip(short bitToFlip){
    short result = bitToFlip;
    int theGuess = rand()%125;
    int theAnswer = 47;

    if(theGuess == theAnswer){
        result = result xor 1;
    }
    return result;
}

//FlipByte
unsigned char flipByte(unsigned char data){
    unsigned short input[8];
    char newChar;

    for(int i =0; i< 8;i++){
        unsigned char temp = (data<< (7-i));
        temp = (temp >> (7-i));
        temp = (temp >> (i));
        input[7-i]=temp;
    }

    for(int i =0;i<8 ; i++){
        input[i] = flipOrNoFlip(input[i]);
    }

    int result = 0;
    for(int i =0; i< 8; i++){
        result += pow(2.0, (double)i)*(int)input[(7-i)];
    }
    newChar = (char)result;
    return newChar;
}

//FlipMessage
deque<unsigned char> flipMessage(deque<unsigned char> message){
    deque<unsigned char> flippingResults;

    while(message.size()!=0){
        unsigned char myData = message.front();
        message.pop_front();
        flippingResults.push_back(flipByte(myData));
    }

    return flippingResults;
}

//PrintOut
void printOut(deque<unsigned char> x){
    while(x.size()!=0){
        cout<< x.front();
        x.pop_front();
    }
}

//Main
int main (int argc, char* argv[])
{
    srand(time(0));
    deque<unsigned char> message;
    deque<unsigned char> erroredOutput;

    message = getMessage();
    erroredOutput = flipMessage(message);
    printOut(erroredOutput);

    return 0;
}

