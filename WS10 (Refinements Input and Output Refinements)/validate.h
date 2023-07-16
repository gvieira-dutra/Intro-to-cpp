#ifndef SICT_VALIDATE_H_
#define SICT_VALIDATE_H_
#include "Displayable.h"
namespace sict {



    template<typename T>

    bool validate(const T& min, const T arrTest[], const int num, bool validate[])  {
        
        bool flag = true;

        for (int i = 0; i < num; i++)
        {
            if (!(arrTest[i] >= min))
            {
                flag = false;
                validate[i] = false;
            }
            else
            {
                validate[i] = true;
            }

        }

        return flag;

    }

}
#endif 