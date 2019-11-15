#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int Decode(string roman) {
  const map<char,int> base = {
  { 'M',1000}, {'D',500}, {'C', 100},
   {'L', 50}, {'X', 10},
  {'V', 5}, {'I',1}
    };
    int num =0;
    map<char,int>::const_iterator it;
    auto fir = base.find(roman[0]);
    if(fir!=base.end())
        num+=fir->second;
    for (int i = 1;roman[i]!='\0';i++){
        auto it = base.find(roman[i]);
        auto prev = base.find(roman[i-1]);
            if(prev->second<it->second){
                int num2 = it->second - prev->second;
                num -=prev->second;
                num+=num2;
            }else{
                num+=it->second;
            }
    }
  return num;
}

std::string Encode(int number) {
    const std::map<int, std::string> bases = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    std::string rnum("");
    for (auto it = bases.crbegin(); it != bases.crend(); ) {
        if (number >= it->first) {
            number -= it->first;
            rnum += it->second;
        } else {
            it++;
        }
    }
    
    return rnum;
}