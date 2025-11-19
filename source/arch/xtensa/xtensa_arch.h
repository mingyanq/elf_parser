/*
 *  xtensa_arch.h
 *
 *  Created on: 2025-11-14
 *      Author: mingyanq
 */

#ifndef __XTENSA_ARCH_H_____
#define __XTENSA_ARCH_H_____

#include "../utility.h"
#include "../../elf_parser.h"





class MmaPipelined : public elf_parser::micro_code<128> {


};





class V341
{

public:

    typedef enum
    {
        XTENSA_V341_F0    = 0x20000,
        XTENSA_V341_F1,
        XTENSA_V341_F11,
        XTENSA_V341_F2,
        XTENSA_V341_F3,
        XTENSA_V341_F4,
        XTENSA_V341_F6,
        XTENSA_V341_F7,
        XTENSA_V341_N0,
        XTENSA_V341_N1,
        XTENSA_V341_N2,
        XTENSA_V341_x16a,
        XTENSA_V341_x16b,
        XTENSA_V341_x24
    }CODE_FORMAT;

    typedef enum
    {
        CONST16_TYPE        = 0x10000,
        CALL8_TYPE          = 0x10001,
        BCA,
        BANYCC

    }INSTRUCTION_ENUM;

    using INSTRU_TYPE   = INSTRUCTION_ENUM;
    using IMM_DATA_T    = int;
    using ADDR_T        = uint32_t;

    static const std::vector<int> vii;

    //-----------------------------------------------------------------------------------
    //
    //
    //
    //-----------------------------------------------------------------------------------
    static const class elf_parser::micro_code<32> fmt_f0_mask;
    static const class elf_parser::micro_code<32> fmt_f1_mask;
    static const class elf_parser::micro_code<32> fmt_f11_mask;
    static const class elf_parser::micro_code<32> fmt_f2_mask;
    static const class elf_parser::micro_code<32> fmt_f3_mask;
    static const class elf_parser::micro_code<32> fmt_f4_mask;
    static const class elf_parser::micro_code<32> fmt_f6_mask;
    static const class elf_parser::micro_code<32> fmt_f7_mask;
    static const class elf_parser::micro_code<32> fmt_n0_mask;
    static const class elf_parser::micro_code<32> fmt_n1_mask;
    static const class elf_parser::micro_code<32> fmt_n2_mask;
    static const class elf_parser::micro_code<32> fmt_x16a_mask;
    static const class elf_parser::micro_code<32> fmt_x16b_mask;
    static const class elf_parser::micro_code<32> fmt_x24_mask;

    static const class elf_parser::micro_code<32> fmt_f0_value;
    static const class elf_parser::micro_code<32> fmt_f1_value;
    static const class elf_parser::micro_code<32> fmt_f11_value;
    static const class elf_parser::micro_code<32> fmt_f2_value;
    static const class elf_parser::micro_code<32> fmt_f3_value;
    static const class elf_parser::micro_code<32> fmt_f4_value;
    static const class elf_parser::micro_code<32> fmt_f6_value;
    static const class elf_parser::micro_code<32> fmt_f7_value;
    static const class elf_parser::micro_code<32> fmt_n0_value;
    static const class elf_parser::micro_code<32> fmt_n1_value;
    static const class elf_parser::micro_code<32> fmt_n2_value;
    static const class elf_parser::micro_code<32> fmt_x16a_value;
    static const class elf_parser::micro_code<32> fmt_x16b_value;
    static const class elf_parser::micro_code<32> fmt_x24_value;


    //-----------------------------------------------------------------------------------
    // CONST16
    //
    //-----------------------------------------------------------------------------------
    static const class elf_parser::micro_code<128> fmt_f0_const16_mask;
    static const class elf_parser::micro_code<128> fmt_f0_const16_value;
    static const       std::vector<int>            fmt_f0_gs_index; 

    static const class elf_parser::micro_code<128> fmt_f1_const16_mask;
    static const class elf_parser::micro_code<128> fmt_f1_const16_value;

    static const class elf_parser::micro_code<128> fmt_f11_const16_mask;
    static const class elf_parser::micro_code<128> fmt_f11_const16_value;

    static const class elf_parser::micro_code<128> fmt_f2_const16_mask;
    static const class elf_parser::micro_code<128> fmt_f2_const16_value;

    static const class elf_parser::micro_code<128> fmt_f3_const16_mask;
    static const class elf_parser::micro_code<128> fmt_f3_const16_value;
    
    static const class elf_parser::micro_code<128> fmt_f4_const16_mask;
    static const class elf_parser::micro_code<128> fmt_f4_const16_value;
    
    static const class elf_parser::micro_code<128> fmt_f6_const16_mask;
    static const class elf_parser::micro_code<128> fmt_f6_const16_value;    

    static const class elf_parser::micro_code<128> fmt_f7_const16_mask;
    static const class elf_parser::micro_code<128> fmt_f7_const16_value;

    static const class elf_parser::micro_code<64>  fmt_n0_const16_mask;
    static const class elf_parser::micro_code<64>  fmt_n0_const16_value;

    static const class elf_parser::micro_code<64>  fmt_n1_const16_mask;
    static const class elf_parser::micro_code<64>  fmt_n1_const16_value;

    static const class elf_parser::micro_code<64>  fmt_n2_const16_mask;
    static const class elf_parser::micro_code<64>  fmt_n2_const16_value;    

    static const class elf_parser::micro_code<24>  fmt_x24_const16_mask;
    static const class elf_parser::micro_code<24>  fmt_x24_const16_value;    

    //-----------------------------------------------------------------------------------
    // BEQ.W15 & BEQ
    //
    //-----------------------------------------------------------------------------------
    static const class elf_parser::micro_code<128> fmt_f0_beqw15_mask;
    static const class elf_parser::micro_code<128> fmt_f0_beqw15_value;

    static const class elf_parser::micro_code<128> fmt_f11_beqw15_mask;
    static const class elf_parser::micro_code<128> fmt_f11_beqw15_value;

    static const class elf_parser::micro_code<128> fmt_f1_beqw15_mask;
    static const class elf_parser::micro_code<128> fmt_f1_beqw15_value;

    static const class elf_parser::micro_code<128> fmt_f2_beqw15_mask;
    static const class elf_parser::micro_code<128> fmt_f2_beqw15_value;
    
    static const class elf_parser::micro_code<128> fmt_f3_beqw15_mask;
    static const class elf_parser::micro_code<128> fmt_f3_beqw15_value;    

    static const class elf_parser::micro_code<128> fmt_f4_beqw15_mask;
    static const class elf_parser::micro_code<128> fmt_f4_beqw15_value;

    static const class elf_parser::micro_code<128> fmt_f6_beqw15_mask;
    static const class elf_parser::micro_code<128> fmt_f6_beqw15_value;
    
    static const class elf_parser::micro_code<128> fmt_f7_beqw15_mask;
    static const class elf_parser::micro_code<128> fmt_f7_beqw15_value;  

    static const class elf_parser::micro_code<64>  fmt_n2_beqw15_mask;
    static const class elf_parser::micro_code<64>  fmt_n2_beqw15_value; 

    static const class elf_parser::micro_code<24>  fmt_x24_beq_mask;
    static const class elf_parser::micro_code<24>  fmt_x24_beq_value; 

    //static constexpr uint32_t fmt0_mask = 0x23456545;


    static INSTRUCTION_ENUM try_decode_fmt(void *ptr)
    {
        elf_parser::micro_code<32>      fmt_in(ptr);


#if 0
        if(     
                ((fmt_in&fmt_f0_mask)==fmt_f0_value && (fmt_in&fmt_f0_mask)==fmt_f0_value) ||
        )
        {

        }
#endif




        if((fmt_in&fmt_f0_mask)==fmt_f0_value)
        {
            elf_parser::micro_code<128>      _fmt_in(ptr);

            if((_fmt_in&fmt_f0_const16_mask)==fmt_f0_const16_value)
            {
                return CONST16_TYPE;
            }



        }

        if((fmt_in&fmt_f1_mask)==fmt_f1_value)
        {

        }

        if((fmt_in&fmt_f11_mask)==fmt_f11_value)
        {

        }

        if((fmt_in&fmt_f2_mask)==fmt_f2_value)
        {

        }
        
        if((fmt_in&fmt_f3_mask)==fmt_f3_value)
        {

        }        

        if((fmt_in&fmt_f4_mask)==fmt_f4_value)
        {

        }

        if((fmt_in&fmt_f6_mask)==fmt_f6_value)
        {

        }

        if((fmt_in&fmt_f7_mask)==fmt_f7_value)
        {

        }

        if((fmt_in&fmt_n0_mask)==fmt_n0_value)
        {

        }

        if((fmt_in&fmt_n1_mask)==fmt_n1_value)
        {

        }

        if((fmt_in&fmt_n2_mask)==fmt_n2_value)
        {

        }

        if((fmt_in&fmt_x16a_mask)==fmt_x16a_value)
        {

        }

        if((fmt_in&fmt_x16b_mask)==fmt_x16b_value)
        {

        }

        if((fmt_in&fmt_x24_mask)==fmt_x24_value)
        {

        }


        return CONST16_TYPE;
    }

    static bool is_absolute_ref(INSTRUCTION_ENUM instruction)
    {
        return false;
    }


    static void encode_new_imm(INSTRU_TYPE type,ADDR_T addr_new,elf_parser::elf_relocations_t reloc_type)
    {
        
    }

    static void encode_new_imm(INSTRU_TYPE type,IMM_DATA_T imm_new)
    {

    }

    static void traverse(INSTRU_TYPE type,IMM_DATA_T imm)
    {
        switch(type)
        {
            //-----------------------------------------------------------------
            //
            //
            //-----------------------------------------------------------------
            case CONST16_TYPE:
            case CALL8_TYPE:
            {
                printf("%s\n",__FUNCTION__);
                break;
            }


            //-----------------------------------------------------------------
            //
            //
            //-----------------------------------------------------------------
            case BCA:
            case BANYCC:
            {
                printf("%s\n",__FUNCTION__);
                break;
            }

            //-----------------------------------------------------------------
            //
            //
            //-----------------------------------------------------------------
            default:
            {
                printf("%s unknown type\n",__FUNCTION__);
                break;
            }


        }

    }


};












#endif
