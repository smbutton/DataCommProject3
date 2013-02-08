/*
*@author Shawn Button
*The hamming code decoding program
*/
//#include "..\include\decode.h"
#include <iostream>
#include <iterator>
#include <deque>
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

//decodeChunk
unsigned char decodeChunk(unsigned char dataFirst,
                          unsigned char dataSecond){

    unsigned short expanded[12];
    unsigned char orig[8];
    unsigned char originalChar = 0;
    deque<short> problems;

    for(int i =0; i< 8;i++){
       unsigned char temp = (dataSecond<< (7-i));
        temp = (temp >> (7-i));
        temp = (temp >> (i));
        expanded[11-i]=temp;
    }
    for(int i =8; i< 12;i++){
       unsigned char temp = (dataFirst<< (7-(i-8)));
        temp = (temp >> (7-(i-8)));
        temp = (temp >> (i-8));
        expanded[11-i]=temp;
    }

short parity1 = expanded[10] xor expanded[8] xor expanded[6] xor expanded[4] xor expanded[2];
short parity2 = expanded[10] xor expanded[9] xor expanded[6] xor expanded[5] xor expanded[2];
short parity4 = expanded[11] xor expanded[6] xor expanded[5] xor expanded[4];
short parity8 = expanded[11] xor expanded[10] xor expanded[9] xor expanded[8];

if(parity1 == expanded[0]){
    problems.push_back(1);
}
if(parity2 == expanded[1]){
    problems.push_back(2);
}
if(parity4 == expanded[3]){
    problems.push_back(4);
}
if(parity8 == expanded[7]){
    problems.push_back(8);
}

if(!problems.empty()){
    int wrongBit = 0;
    while(!problems.empty()){
        wrongBit += problems.front();
        problems.pop_front();
    }
    expanded[wrongBit-1] = expanded[wrongBit-1] xor 1;
}

orig[0] = expanded[2];
orig[1] = expanded[4];
orig[2] = expanded[5];
orig[3] = expanded[6];
orig[4] = expanded[8];
orig[5] = expanded[9];
orig[6] = expanded[10];
orig[7] = expanded[11];
int result = 0;

for(int i =0; i< 8; i++){
    result += pow(2.0, (double)i)*(int)orig[(7-i)];
}
originalChar = (char)result;

return originalChar;
}

//decodeMessage
deque<unsigned char> decodeMessage(deque<unsigned char> message){
    deque<unsigned char> fullyDecoded;

    while(message.size()!=0){
        unsigned char myDataFront = message.front();
        message.pop_front();

        unsigned char myDataBack = message.front();
        message.pop_front();
        fullyDecoded.push_back(decodeChunk(myDataFront,myDataBack));
    }
    return fullyDecoded;
}

//PrintOut
void printOut(deque<unsigned char> x){
    while(x.size()!=0){
        cout<< x.front();
        x.pop_front();
    }
}


int main (int argc, char* argv[])
{
    deque<unsigned char> message;
    deque<unsigned char> decoded;

    message = getMessage();
    decoded = decodeMessage(message);
    printOut(decoded);

    return 0;
}

