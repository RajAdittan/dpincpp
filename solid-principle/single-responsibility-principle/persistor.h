//
// Created by rajam on 8/17/2018.
//

#ifndef SINGLE_RESPONSIBILITY_PRINCIPLE_PERSISTOR_H
#define SINGLE_RESPONSIBILITY_PRINCIPLE_PERSISTOR_H

#include "journal.h"

#include <iostream>
using namespace std;

namespace solid {
    namespace principle {
        namespace single_responsibility {

            class persistor {
            public:
                persistor(journal &journal, ostream &output)
                : journal_(journal), output_(output) {
                }

                void save() const;

            private:
                journal journal_;
                ostream& output_;
            };
        }
    }
}


#endif //SINGLE_RESPONSIBILITY_PRINCIPLE_PERSISTOR_H
