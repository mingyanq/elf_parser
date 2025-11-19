//
//  main.cpp
//  elf_parser
//
//  Created by 秦明岩 on 2025/11/18.
//

#include <iostream>


#include "../elf_parser.h"

#include "../arch/xtensa/xtensa_arch.h"



int main(int argc, const char * argv[]) {

    class   elf_parser::elf_info_parser   elf_obj("/Users/qinmingyan/Desktop/med/elf_parser/platform/odsp_debug2.out");


    elf_obj.debug_out();

    
    
    return 0;
}
