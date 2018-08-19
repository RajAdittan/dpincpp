//
// Created by rajam on 8/17/2018.
//

#ifndef DPINCPP_JOURNAL_H
#define DPINCPP_JOURNAL_H

#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
using namespace std;
using namespace boost;

namespace solid {
    namespace principle {
        namespace single_responsibility {
            class journal {
                string title;
                vector<string> entries;

            public:
                explicit journal(const string &title);
                void add_entry(const string &entry);
                string to_string() const;
            };
        }
    }
}

#endif //DPINCPP_JOURNAL_H
