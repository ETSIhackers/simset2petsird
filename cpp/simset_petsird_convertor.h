/*
    Copyright 2026, University Medical Center Groningen

    SPDX-License-Identifier: Apache-2.0
    See STIR/LICENSE.txt for details.

*/

#ifndef SIMSETPETSIRDCONVERTOR_H
#define SIMSETPETSIRDCONVERTOR_H

#include <string>
#include <memory>

class SIMSETPETSIRDConvertor
{
    public: 
        SIMSETPETSIRDConvertor(const std::string& out_filename, const std::string& in_filename);
        void process_data(); 
    private: 
        // Output file name to write to, will delete previous file if it exists
        std::string out_filename;
        // Input file name to read from
        std::string in_filename;
};


#endif