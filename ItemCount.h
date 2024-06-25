/*Chris Bridges
CS 210
Southern New Hampshire University
June 19 2024*/

#pragma once
#ifndef ITEM_COUNT_H
#define ITEM_COUNT_H

#include <map>
#include <string>

//Declaring ItemCount class
class ItemCount {
private:
    std::map<std::string, int> itemFrequency;   //Stores count frequency

    void readFile(const std::string& fileName); //Read file method

public:
    ItemCount(const std::string& fileName);     //Constructor

    int getCount(const std::string& item);  //Gets count

    void displayCount();    //Displays count

    void displayHistogram();    //Displays histogram

    void saveCount(const std::string& fileName);    //Outputs to file 
};

#endif
