/*
 *  elf_parser.cpp
 *
 *  Created on: 2025-11-06
 *      Author: mingyanq
 */
#include "elf_parser.h"

#include "./arch/xtensa/xtensa_arch.h"




#if 0
class ME1
{
public:

    
    typedef enum
    {
        CONST16_TYPE        = 0x10000,
        CALL8_TYPE          = 0x10001,
        BCC_W15_TYPE,
        BCSNY

    }INSTRUCTION_ENUM;

    using INSTRU_TYPE   = INSTRUCTION_ENUM;
    using IMM_DATA_T    = int;

};




class elf_parser::micro_code<128> mef({1,2,3});
class elf_parser::micro_code<128> mef2({1,2,3});
class elf_parser::micro_code<128> mef3({1,2,3,45});
class elf_parser::micro_code<64> me3f({1,2,3,23});
class elf_parser::micro_code<24> me33f({1,2,3});
class elf_parser::micro_code<16> mecf({1,2,3,7});


class elf_parser::micro_code<32> format_f0({1,2,3,7});


int  main(int argc,char *argv[])
{


    class   elf_parser::elf_info_parser   elf_obj("/Users/qinmingyan/Desktop/med/elf_parser/platform/odsp_debug2.out");


    elf_obj.debug_out();

    return 0;



    auto res = mef & 0x12346578ULL;

    //std::cout   << ME1::CDA_C << std::endl;
    std::cout   << ME1::CALL8_TYPE << std::endl;
    std::cout   << V341::CALL8_TYPE << std::endl;

    ME1::INSTRU_TYPE sc = ME1::CONST16_TYPE;

    V341::CODE_FORMAT   form = V341::XTENSA_V341_F11;

    if(mef==mef2)
    {
        std::cout << "Hello World!\n" << std::endl;
    }

    mef.print();

    (mef & mef3).print();


    if(mef==mef3)
    {
        std::cout << "Hello World3!\n" << std::endl;
    }
    return 0;
}
#endif
