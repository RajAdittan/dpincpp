//
// Created by rajam on 8/17/2018.
//

#include "journal.h"

namespace solid {
    namespace principle {
        namespace single_responsibility {


            journal::journal(const string &title) : title(title) {

            }

            void journal::add_entry(const string &entry) {
                static int count = 1;
                entries.push_back(lexical_cast<string>(count++) + ": " + entry);
            }

            string journal::to_string() const {
                stringstream ss;
                ss << "title:" << title << '\n';
                for(string entry : entries) {
                    ss << '\t' << entry << '\n';
                }
                return ss.str();
            }
        }
    }
}