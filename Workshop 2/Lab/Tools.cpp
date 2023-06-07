#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "Tools.h"
#include "Package.h"

FILE* fp;

namespace sdds {
    int openFile_r(const char filename[]) { // Fully provided
        fp = fopen(filename_r, "r");
        return fp != NULL;
    }
    int noOfTraces() {  // Fully provided
        int noOfTraces = 0;
        char ch;
        while (fscanf(fp, "%c", &ch) == 1) {
            noOfTraces += (ch == '\n');
        }
        rewind(fp);
        return noOfTraces;
    }
    

    // To Do: read functions (4 overloaded read functions)
    
       

    int read(char pkgName[]) {

        return fscanf(fp, "%60[^\n]\n", pkgName) == 1;
    }

    int read(int& integerReader) {

        
        return fscanf(fp, "%d,", &integerReader) == 1;
    }

    int read(double& doubleReader) {

        return fscanf(fp, "%lf,", &doubleReader) == 1;
    }

    int read(char& singleChar) {

        return fscanf(fp, "%[^ \t\n\r\v\f,]%*c", &singleChar) == 1;
    }

    

    void closefile() { // Fully provided
        if (fp) fclose(fp);
    }
    
    void strCpy(char* str1, const char* str2) { // Fully provided 
        while (*str2) {
            *str1++ = *str2++;
        }
        *str1 = 0;
    }
    int strLen(const char* str) {  // Fully provided
        int i = -1;
        while (str[++i]);
        return i;
    }
}