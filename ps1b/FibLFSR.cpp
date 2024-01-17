#include "FibLFSR.hpp"

FibLFSR::FibLFSR(std::string seed){
    string sentence = seed;
    // alphabet password to binary
    int alpha= 0;
    for(int i = 0; i < (signed)sentence.length(); i++)
    {
        if(isalpha(sentence.at(i))||sentence.at(i)>=2){
        alpha++;
        break;
        }
    }
    if(alpha > 0){
        
        int number= 0;
        string binary;
        for(int i=0; i<(signed)sentence.length(); i++){
            number += sentence.at(i);
        }

        while(number!=0){
            binary = ((number%2 == 0 ? "0" : "1" ) + binary); 
            number/=2;
        }
        sentence = binary;
    }
    while(sentence.length() < 16){
        sentence = "0" + sentence;
    }
    iSeed = sentence;
    
}
int FibLFSR::step() {
    string aSeed = getSeed();
    int output;
    string out;
    
    //addition works as xor
    output = (aSeed.at(0) + aSeed.at(2) + aSeed.at(3) + aSeed.at(5)) & 0x00001;
    aSeed.erase(aSeed.begin());
    
    //changing the output to string
    if (output == 1) out = "1";
    else if (output == 0) out = "0";
    aSeed = aSeed + out;
    setSeed(aSeed);

    return output;
}


int FibLFSR::generate(int k){
        int result = 0;
        for (int i = 0; i < k; i++)
        {
            result *= 2;
            result += step();
        }
        return result;
    }

ostream& operator<<(std::ostream& out, const FibLFSR& lfsr) {
    out << lfsr.getSeed();
    return out;
}


FibLFSR::~FibLFSR() {
    iSeed.clear();
}
