//
// Created by rajam on 8/17/2018.
//

#include "persistor.h"


namespace solid {
    namespace principle {
        namespace single_responsibility {

void persistor::save() const {
    output_ << journal_.to_string();
}

        }
    }
}