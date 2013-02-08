/*
*@author Shawn Button
*The hamming code encoding program
*/
//#include "..\include\encode.h"
#include <iostream>
#include <iterator>
#include <deque>
#include <string>
#include <iterator>
using namespace std;


deque<char> getMessage(){

    deque<char> result;
    //char x;
    //while(cin>>x){
    //    result.push_back(x);
    //}
    cin >> noskipws;
  istream_iterator<char> itr(cin);
  istream_iterator<char> end;
  string results(itr, end);

  for(int i = 0; i< results.size(); i++){
    result.push_back(results.at(i));
  }
    /*result.push_back('a');
    result.push_back('b');
    result.push_back('c');
*/
    return result;
}

unsigned short encodeByte(char data){
    short expanded = 0;
    short orig[8];
    short hammed[12];

    for(int i =0; i< 8;i++){
       unsigned char temp = data;

       if(i == 7){
        temp = (temp >> (i));
        orig[0]=temp;
       }else{
        temp = (temp<< (7-i));
        temp = (temp >> (7-i));
        temp = (temp >> (i));
        orig[7-i]=temp;
       }
    }

hammed[11] = orig[7];
hammed[10] = orig[6];
hammed[9] = orig[5];
hammed[8] = orig[4];
hammed[6] = orig[3];
hammed[5] = orig[2];
hammed[4] = orig[1];
hammed[2] = orig[0];

hammed[7] = hammed[11] xor hammed[10] xor
            hammed[9] xor hammed[8];

hammed[3] = hammed[11] xor hammed[6] xor
            hammed[5] xor hammed[4];

hammed[1] = hammed[10] xor hammed[9] xor
            hammed[6] xor hammed[5] xor hammed[2];

hammed[0] = hammed[10] xor hammed[8] xor
            hammed[6] xor hammed[4] xor hammed[2];

for(int i =0; i< 12; i++){
    hammed[i] = hammed[i] << 11-i;
    expanded = expanded | hammed[i];
}

return expanded;
}

deque<unsigned short> encodeMessage(deque<char> message){
    deque<unsigned short> fullyEncoded;

    while(message.size()!=0){
        fullyEncoded.push_back(encodeByte(message.front()));
        message.pop_front();
    }

    return fullyEncoded;
}

//printOut
void printOut(deque<unsigned short> x){
    while(x.size()!=0){
        unsigned char a = x.front() >> 8;
        unsigned char b = (x.front() << 8) >> 8;

        cout<<(int)a<<" "<<(int)b<<" ";
        x.pop_front();
    }
}

//Main
int main (int argc, char* argv[]){
    deque<char> message;
    deque<unsigned short> encoded;

    message = getMessage();//
    encoded = encodeMessage(message);
    printOut(encoded);

    return 0;
}

