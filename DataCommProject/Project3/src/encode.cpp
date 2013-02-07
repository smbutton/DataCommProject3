#include "..\include\encode.h"
#include <iostream>
#include <iterator>


encode::encode()
{
    //ctor
}

encode::~encode()
{
    //dtor
}

using namespace std;

int main ()
{
  cin >> noskipws;

// use stream iterators to copy the stream to a string
  istream_iterator<char> it(cin);
  istream_iterator<char> end;
  string results(it, end);

    cout<< results;
  return 0;
}
