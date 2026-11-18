/*
     Copyright 2026, University Medical Center Groningen
     
    SPDX-License-Identifier: Apache-2.0
    See STIR/LICENSE.txt for details.

*/

#include "simset_petsird_convertor.h"

#include <iostream>
#include <fstream>

extern "C"
{
#include <LbTypes.h>
//#include <LbFile.h>
//#include <PhgHdr.h>
#include <bin.phg.h>
#include <PhoHFile.h>
#include <print.header.h>
}

#undef true
#undef false

#include "petsird/binary/protocols.h"
#include "petsird_helpers.h"
#include "petsird_helpers/create.h"
#include "petsird_helpers/geometry.h"

namespace {
char phgrdhstHistName[1024]{};
PhoHFileHdrTy phgrdhstHdrParams{};
char phgrdhstHistParamsName[1024]{};
}

SIMSETPETSIRDConvertor::SIMSETPETSIRDConvertor(const std::string& out_filename, const std::string& in_filename)
:out_filename(out_filename), in_filename(in_filename)
{

}

petsird::Header
get_header()
{

}

void 
SIMSETPETSIRDConvertor::process_data()
{
    std::cout << "Converting SimSET history data to petsird format...\n"
            << "\t- Input file: " << this->in_filename << "\n"
            << "\t- Output file: " << this->out_filename << "\n"
            << std::endl;
        
    double SubObjCurTimeBinDuration = 0.0;

    // The dirty trick we did in SimSETListmodeInputFileFormat::is_SimSET_signature()
    char** argv = new char*[3];
    argv[0] = nullptr;
    argv[1] = nullptr;
    argv[2] = nullptr;

    petsird::Header header_info = get_header();
}

int
main(int argc, char* argv[])
{

    std::cout << "Converting SIMSET to PETSIRD" << std::endl;

    if (argc < 3 || argc > 4)
    {
      std::cout << "Converts list mode data from STIR to petsird format.\n"
                   "Usage: "
                << argv[0] << " <output_filename> <input_filename> [norm.par]\n";
      return EXIT_FAILURE;
    }

    SIMSETPETSIRDConvertor my_class(argv[1], argv[2]);

    my_class.process_data();
    return EXIT_SUCCESS;
}