//
//  SubstringSearch.h
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 16/08/21.
//

#ifndef SubstringSearch_h
#define SubstringSearch_h

#include <iostream>

class SubstringSearch {
        
    
public:
    int bruteForceSearch(char* pattern, char* text) {
        
        int index = -1;
        
        size_t patternSize = std::strlen(pattern);
        size_t textSize = std::strlen(text);
        
        for (int i = 0; i < textSize - patternSize + 1; i++) {
            int j = 0;
            while (j < patternSize) {
                if (pattern[j] != text[i+j]) {
                    break;
                }
                j++;
            }
            if(j == patternSize) {
                index = i;
            }
        }
        
        return  index;
        
    }
};


#endif /* SubstringSearch_h */
