#ifndef BELISH_FIO_H
#define BELISH_FIO_H

#include <fstream>
#include <sstream>
#include <string>
#include "trans.h"

namespace Belish {
    char* readFileCPTR(const string&, ULL&);
    bool readFile(const string&, string&);// true为打开失败, false为成功
    bool writeFile(const string&, const string&);
}

#endif //BELISH_FIO_H
