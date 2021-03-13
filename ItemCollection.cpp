#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include "ItemCollection.hpp"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

// function to return the hash value based on the first digit
unsigned int hashfct1(unsigned int barcode) {
  // TO BE COMPLETED
    unsigned int d = barcode/1000000;
    d = d%10;
    return d;
}

// function to return the hash value based on the second digit
unsigned int hashfct2(unsigned int barcode) {
  // TO BE COMPLETED
    unsigned int d = barcode/100000;
    d = d%10;
    return d;
}

// function to return the hash value based on the third digit
unsigned int hashfct3(unsigned int barcode) {
  // TO BE COMPLETED
    unsigned int d = barcode/10000;
    d = d%10;
    return d;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(unsigned int barcode) {
  // TO BE COMPLETED
    unsigned int d = barcode/1000;
    d = d%10;
    return d;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(unsigned int barcode) {
    // TO BE COMPLETED
    unsigned int d = barcode/100;
    d = d%10;
    return d;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct6(unsigned int barcode) {
    // TO BE COMPLETED
    unsigned int d = barcode/10;
    d = d%10;
    return d;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct7(unsigned int barcode) {
    // TO BE COMPLETED
    unsigned int d = barcode/1;
    d = d%10;
    return d;
}


// Constructor for struct Item
Item::Item(string itemColor, string itemShape, string itemBrand,
		 unsigned int barcode):itemColor_(itemColor),itemShape_(itemShape), itemBrand_(itemBrand),
				       barcode_(barcode)
{};

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void ItemCollection::readTextfile(string filename) {
  ifstream myfile(filename);

  if (myfile.is_open()) {
    cout << "Successfully opened file " << filename << endl;
    string itemColor;
    string itemShape;
    string itemBrand;
    unsigned int barcode;
    while (myfile >> itemColor >> itemShape >> itemBrand >> barcode) {
			if (itemColor.size() > 0)
      	addItem(itemColor, itemShape, itemBrand, barcode);
    }
    myfile.close();
  }
  else
    throw std::invalid_argument("Could not open file " + filename);
}

void ItemCollection::addItem(string itemColor, string itemShape, string itemBrand, unsigned int barcode) {
  // TO BE COMPLETED
  // function that adds the specified pair of glasses to main display (i.e., to all hash tables)
    Item newItem(itemColor, itemShape, itemBrand, barcode);
    hT1[barcode] = newItem;
    hT2[barcode] = newItem;
    hT3[barcode] = newItem;
    hT4[barcode] = newItem;
    hT5[barcode] = newItem;
    hT6[barcode] = newItem;
    hT7[barcode] = newItem;



}

bool ItemCollection::removeItem(unsigned int barcode) {
  // TO BE COMPLETED
  // function that removes the pair of glasses specified by the barcode from the display
  // if pair is found, then it is removed and the function returns true
  // else returns false


    if(hT1.find(barcode)== hT1.end()|| hT2.find(barcode)== hT2.end() || hT3.find(barcode)== hT3.end() || hT4.find(barcode)== hT4.end()|| hT5.find(barcode)== hT5.end()|| hT6.find(barcode)== hT6.end()|| hT7.find(barcode)== hT7.end() )
    {
        return false;
    }
    hT1.erase(barcode);
    hT2.erase(barcode);
    hT3.erase(barcode);
    hT4.erase(barcode);
    hT5.erase(barcode);
    hT6.erase(barcode);
    hT7.erase(barcode);
    return true;

}

unsigned int ItemCollection::bestHashing() {
  // TO BE COMPLETED
  // function that decides the best has function, i.e. the ones among
  // fct1-fct7 that creates the most balanced hash table for the current
  // ItemCollection data member allItems

	// Hints:
	// Calculate the balance of each hashtable, one by one.
	/*
	 for (unsigned i=0; i<10; ++i) {
    cout << hT1.bucket_size(i); // Call bucket_size() to get the size of each bucket
  }
	*/
	// Then, calculate the lowest balance

    //using http://www.cplusplus.com/reference/algorithm/min_element/ for reference for max_loc and min_loc

    unsigned int balance[8];
    balance[0] = 0;
    unsigned int min_loc, max_loc;
    unsigned int minValue;
    unsigned int value[10];
    for(unsigned int i = 0; i < 10; i++)
    {
        value[i] = hT1.bucket_size(i);
        cout << hT1.bucket_size(i);
    }
    min_loc = *std::min_element(value,value+10);
    max_loc = *std::max_element(value,value+10);
    balance[1] = max_loc - min_loc;

    for(unsigned int i = 0; i < 10; i++)
    {
        value[i] = hT2.bucket_size(i);
        cout << hT2.bucket_size(i);
    }
    min_loc = *std::min_element(value,value+10);
    max_loc = *std::max_element(value,value+10);
    balance[2] = max_loc - min_loc;
    //minValue = balance[2];
    //if(minValue > balance)

    for(unsigned int i = 0; i < 10; i++)
    {
        value[i] = hT3.bucket_size(i);
        cout << hT3.bucket_size(i);
    }
    min_loc = *std::min_element(value,value+10);
    max_loc = *std::max_element(value,value+10);
    balance[3] = max_loc - min_loc;

    for(unsigned int i = 0; i < 10; i++)
    {
        value[i] = hT4.bucket_size(i);
        cout << hT4.bucket_size(i);
    }
    min_loc = *std::min_element(value,value+10);
    max_loc = *std::max_element(value,value+10);
    balance[4] = max_loc - min_loc;

    for(unsigned int i = 0; i < 10; i++)
    {
        value[i] = hT5.bucket_size(i);
        cout << hT5.bucket_size(i);
    }
    min_loc = *std::min_element(value,value+10);
    max_loc = *std::max_element(value,value+10);
    balance[5] = max_loc - min_loc;

    for(unsigned int i = 0; i < 10; i++)
    {
        value[i] = hT6.bucket_size(i);
        cout << hT6.bucket_size(i);
    }
    min_loc = *std::min_element(value,value+10);
    max_loc = *std::max_element(value,value+10);
    balance[6] = max_loc - min_loc;

    for(unsigned int i = 0; i < 10; i++)
    {
        value[i] = hT7.bucket_size(i);
        cout << hT7.bucket_size(i);
    }
    min_loc = *std::min_element(value,value+10);
    max_loc = *std::max_element(value,value+10);
    balance[7] = max_loc - min_loc;

    minValue = balance[1];
    for(size_t i = 1; i< 8; i++)
    {
        if(minValue > balance[i])
        {
            minValue = balance[i];
            min_loc = i;
        }
    }

    return min_loc;
}

// ALREADY COMPLETED
size_t ItemCollection::size() {
    if((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size())|| (hT1.size() != hT6.size()) || (hT1.size() != hT7.size()))
   {
    throw std::length_error("Hash table sizes are not the same");
  }
	return hT1.size();
}
