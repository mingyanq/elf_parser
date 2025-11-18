
/*
 *  elf_parser.h
 *
 *  Created on: 2025-11-06
 *      Author: mingyanq
 */

#ifndef __ELF__PRASER_H_____
#define __ELF__PRASER_H_____

#include <stdint.h>

//#include <cstdint>
#include <iostream>
#include <fstream>
#include <vector>

namespace elf_parser
{


#ifndef __cplusplus
typedef     char            bool;

#ifndef     true
#define     true            1
#endif

#ifndef     false
#define     false           0
#endif

#ifndef     nullptr
#define     nullptr         NULL
#endif

#endif



typedef     uint16_t        Elf32_Half;
typedef     uint32_t        Elf32_Word;
typedef     int32_t         Elf32_Sword;
typedef     uint32_t        Elf32_Addr;
typedef     uint32_t        Elf32_Off;

//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
#define EI_NIDENT 16
typedef struct {
    unsigned char e_ident[EI_NIDENT];
    Elf32_Half e_type;
    Elf32_Half e_machine;
    Elf32_Word e_version;
    Elf32_Addr e_entry;
    Elf32_Off e_phoff;
    Elf32_Off e_shoff;
    Elf32_Word e_flags;
    Elf32_Half e_ehsize;
    Elf32_Half e_phentsize;
    Elf32_Half e_phnum;
    Elf32_Half e_shentsize;
    Elf32_Half e_shnum;
    Elf32_Half e_shstrndx;
} Elf32_Ehdr;

//-------------------------------------------------------------------
// Section Header
//-------------------------------------------------------------------
typedef struct {
    Elf32_Word sh_name;
    Elf32_Word sh_type;
    Elf32_Word sh_flags;
    Elf32_Addr sh_addr;
    Elf32_Off sh_offset;
    Elf32_Word sh_size;
    Elf32_Word sh_link;
    Elf32_Word sh_info;
    Elf32_Word sh_addralign;
    Elf32_Word sh_entsize;
} Elf32_Shdr;

#define SHT_NULL            0
#define SHT_PROGBITS        1
#define SHT_SYMTAB          2
#define SHT_STRTAB          3
#define SHT_RELA            4
#define SHT_HASH            5
#define SHT_DYNAMIC         6
#define SHT_NOTE            7
#define SHT_NOBITS          8
#define SHT_REL             9
#define SHT_SHLIB           10
#define SHT_DYNSYM          11
#define SHT_LOPROC          0x70000000
#define SHT_HIPROC          0x7fffffff
#define SHT_LOUSER          0x80000000
#define SHT_HIUSER          0xffffffff

//-------------------------------------------------------------------
// Program Header
//-------------------------------------------------------------------
typedef struct {
    Elf32_Word p_type;
    Elf32_Off p_offset;
    Elf32_Addr p_vaddr;
    Elf32_Addr p_paddr;
    Elf32_Word p_filesz;
    Elf32_Word p_memsz;
    Elf32_Word p_flags;
    Elf32_Word p_align;
} Elf32_Phdr;

//-------------------------------------------------------------------
// Symbol table
//-------------------------------------------------------------------
typedef struct {
    Elf32_Word st_name;
    Elf32_Addr st_value;
    Elf32_Word st_size;
    unsigned char st_info;
    unsigned char st_other;
    Elf32_Half st_shndx;
} Elf32_Sym;

#define     STT_NOTYPE      0
#define     STT_OBJECT      1
#define     STT_FUNC        2
#define     STT_SECTION     3
#define     STT_FILE        4
#define     STT_LOPROC      13
#define     STT_HIPROC      15

//-------------------------------------------------------------------
// Relocation Entries
//-------------------------------------------------------------------
typedef struct
{
  Elf32_Addr r_offset;
  Elf32_Word r_info;
} Elf32_Rel;

typedef struct
{
  Elf32_Addr r_offset;
  Elf32_Word r_info;
  Elf32_Sword r_addend;
} Elf32_Rela;

#define  ELF32_R_SYM(i)         ((i)>>8)
#define  ELF32_R_TYPE(i)        ((unsigned  char)(i))
#define  ELF32_R_INFO(s,t)      (((s)<<8)+(unsigned  char)(t))




#define       IS_RW_SECTION_FLAG    1
#define       IS_RO_SECTION_FLAG    2

typedef struct 
{
  Elf32_Addr  sh_addr_new;
  Elf32_Word  sh_size;

  char        *host_addr;

  uint32_t    size_align;
  uint32_t    flag;

}section_new_info;


//-----------------------------------------------------------------------------
// Description: Special Section Indexes.
//
//
//
//-----------------------------------------------------------------------------
#define     SHN_UNDEF           0
#define     SHN_LORESERVE       0xff00
#define     SHN_LOPROC          0xff00
#define     SHN_HIPROC          0xff1f
#define     SHN_ABS             0xfff1
#define     SHN_COMMON          0xfff2
#define     SHN_HIRESERVE       0xffff



//-----------------------------------------------------------------------------
// Description: Section Type.
//
//
//
//-----------------------------------------------------------------------------
#define     SHT_NULL            0
#define     SHT_PROGBITS        1
#define     SHT_SYMTAB          2
#define     SHT_STRTAB          3
#define     SHT_RELA            4
#define     SHT_HASH            5
#define     SHT_DYNAMIC         6
#define     SHT_NOTE            7
#define     SHT_NOBITS          8
#define     SHT_REL             9
#define     SHT_SHLIB           10
#define     SHT_DYNSYM          11
#define     SHT_LOPROC          0x70000000
#define     SHT_HIPROC          0x7fffffff
#define     SHT_LOUSER          0x80000000
#define     SHT_HIUSER          0xffffffff










typedef enum {
  



  
    



    //=================================================================================================================
    //
    //                                               XTENSA ARC
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //=================================================================================================================

        
    R_XTENSA_NONE = 0,
    R_XTENSA_32 = 1,

    //---------------------------------------------------------------------------
    // RTLD, GLOB_DAT, JMP_SLOT, and PLT are used for Linux style shared object 
    // files where the same code might need to execute from different virtual 
    // addresses (not applicable for this situation).
    //
    //
    //---------------------------------------------------------------------------
    R_XTENSA_RTLD = 2,
    R_XTENSA_GLOB_DAT = 3,
    R_XTENSA_JMP_SLOT = 4,
    R_XTENSA_RELATIVE = 5,
    R_XTENSA_PLT = 6,

    //---------------------------------------------------------------------------
    // R_XTENSA_OP0, _OP1, and _OP2 are old and replaced by the R_XTENSA_SLOTX_OP
    //
    //
    //
    //---------------------------------------------------------------------------
    R_XTENSA_OP0 = 8,           
    R_XTENSA_OP1 = 9,
    R_XTENSA_OP2 = 10,

    //---------------------------------------------------------------------------
    // ASM_EXPAND, ASM_SIMPLIFY, GNU_VTINHERIT, GNU_VTENTRY are use to provide 
    // information to the linker.  The linker has already used them in preparing 
    // the object used by our library loader.
    //
    //
    //
    //
    //---------------------------------------------------------------------------
    R_XTENSA_ASM_EXPAND = 11,
    R_XTENSA_ASM_SIMPLIFY = 12,
    R_XTENSA_GNU_VTINHERIT = 15,
    R_XTENSA_GNU_VTENTRY = 16,

    //---------------------------------------------------------------------------
    // R_XTENSA_DIFF8, R_XTENSA_DIFF16, and R_XTENSA_DIFF32 … are used for linker 
    // relaxation and again, they are already processed before the object is used 
    // by our library loader.
    //
    //
    //
    //---------------------------------------------------------------------------
    R_XTENSA_DIFF8 = 17,
    R_XTENSA_DIFF16 = 18,
    R_XTENSA_DIFF32 = 19,

    //---------------------------------------------------------------------------
    //
    //
    //
    //
    //---------------------------------------------------------------------------
    R_XTENSA_SLOT0_OP = 20,
    R_XTENSA_SLOT1_OP = 21,
    R_XTENSA_SLOT2_OP = 22,
    R_XTENSA_SLOT3_OP = 23,
    R_XTENSA_SLOT4_OP = 24,
    R_XTENSA_SLOT5_OP = 25,
    R_XTENSA_SLOT6_OP = 26,
    R_XTENSA_SLOT7_OP = 27,
    R_XTENSA_SLOT8_OP = 28,
    R_XTENSA_SLOT9_OP = 29,
    R_XTENSA_SLOT10_OP = 30,
    R_XTENSA_SLOT11_OP = 31,
    R_XTENSA_SLOT12_OP = 32,
    R_XTENSA_SLOT13_OP = 33,
    R_XTENSA_SLOT14_OP = 34,
    R_XTENSA_SLOT0_ALT = 35,
    R_XTENSA_SLOT1_ALT = 36,
    R_XTENSA_SLOT2_ALT = 37,
    R_XTENSA_SLOT3_ALT = 38,
    R_XTENSA_SLOT4_ALT = 39,
    R_XTENSA_SLOT5_ALT = 40,
    R_XTENSA_SLOT6_ALT = 41,
    R_XTENSA_SLOT7_ALT = 42,
    R_XTENSA_SLOT8_ALT = 43,
    R_XTENSA_SLOT9_ALT = 44,
    R_XTENSA_SLOT10_ALT = 45,
    R_XTENSA_SLOT11_ALT = 46,
    R_XTENSA_SLOT12_ALT = 47,
    R_XTENSA_SLOT13_ALT = 48,
    R_XTENSA_SLOT14_ALT = 49
} elf_relocations_t;







#if 0

struct elf_context
{
    //---------------------------------------------------------------------------------------------
    // Description: Base information about one ELF;
    //
    //
    //---------------------------------------------------------------------------------------------
    char                        *p_elf_ary;
    int64_t                     elf_bytes;

    Elf32_Ehdr                  elf_head;


    Elf32_Shdr                  *p_shead;
    int32_t                     total_num_sec;

    Elf32_Sym                   *p_sybtbl;

    const char                  *p_str_tbl;         // name of section
    const char                  *p_str_tbl2;        // name of symbol

    //---------------------------------------------------------------------------------------------
    //
    //
    //
    //---------------------------------------------------------------------------------------------
    struct section_info         *p_shead_info;

    uint64_t                    allocated_bytes_for_rw;
    uint64_t                    allocated_bytes_for_ro_x;

};

#endif
class elf_info_parser
{


public:


#if 0
// 加载二进制文件到 vector<unsigned char>
bool loadBinaryFile(const std::string& filename, std::vector<unsigned char>& data) {
    // 以二进制模式打开文件（ios::binary）
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return false;
    }

    // 获取文件大小（ios::ate 表示打开时定位到文件末尾）
    std::streamsize fileSize = file.tellg();
    if (fileSize <= 0) {
        std::cerr << "文件为空或大小获取失败" << std::endl;
        return false;
    }

    // 定位到文件开头
    file.seekg(0, std::ios::beg);

    // 分配内存（resize 确保 vector 有足够空间）
    data.resize(static_cast<size_t>(fileSize));

    // 读取文件内容到 vector（vector 的 data() 返回底层数组指针）
    if (!file.read(reinterpret_cast<char*>(data.data()), fileSize)) {
        std::cerr << "文件读取失败" << std::endl;
        data.clear();
        return false;
    }

    return true;
}
#endif
    elf_info_parser(const std::string &file_path)
    {
        std::ifstream file(file_path, std::ios::binary | std::ios::ate);

        if (!file.is_open()) 
        {
            std::cerr << "file path invalid: " << file_path << std::endl;
            exit(0);
        }

        
        std::streamsize fileSize = file.tellg();
        if (fileSize <= 0) 
        {
            std::cerr << "empty file or get file failed" << std::endl;
            exit(0);
        }     

        // 定位到文件开头
        file.seekg(0, std::ios::beg);

        // 分配内存（resize 确保 vector 有足够空间）
        file_container.resize(static_cast<size_t>(fileSize));

        // 读取文件内容到 vector（vector 的 data() 返回底层数组指针）
        if (!file.read(reinterpret_cast<char*>(file_container.data()), fileSize)) 
        {
            std::cerr << "read file failed" << std::endl;
            file_container.clear();
            exit(0);
        }


        do_elf_info_parse();

    
    }

    

    elf_info_parser(const char *_file,int64_t nbytes):file_container(_file,_file+nbytes),p_shead(NULL)
    {
        //p_elf_head  = (Elf32_Ehdr*)_file;

        do_elf_info_parse();



    }

    void    debug_out(void)
    {


        FILE *p_fout =
        fopen("resddd.bin","wb");

        fwrite(&p_str_tbl[0],1,34243,p_fout);
        fclose(p_fout);

        printf("p str tbl2 = %s 0x%x 0x%llx\n",p_str_tbl2,p_str_tbl2[0],(uint64_t)p_str_tbl2);
        printf("p str tbl  = %s 0x%x 0x%llx\n",p_str_tbl,p_str_tbl[0],(uint64_t)p_str_tbl);

        for(int i = 0; i < EI_NIDENT; i++)
        {
            std::cout  << i << "=" << p_elf_head->e_ident[i] << std::endl;
        }
        std::cout << std::endl;
        


        std::cout << *p_str_tbl2 << std::endl;
    }

private:
    void    do_elf_info_parse(void)
    {

        p_elf_head      = reinterpret_cast<Elf32_Ehdr*>(file_container.data());

        p_shead         = reinterpret_cast<Elf32_Shdr*>(file_container.data() + p_elf_head->e_shoff);

        p_str_tbl       = reinterpret_cast<const char*>(file_container.data() + p_shead[p_elf_head->e_shstrndx].sh_offset); // name of section

        //-----------------------------------------------------------------------------------------
        //
        //
        //
        //
        //
        //-----------------------------------------------------------------------------------------
        for (int i = 0; i < p_elf_head->e_shnum; i++)
        {
            if (SHT_SYMTAB == p_shead[i].sh_type)
            {
                //p_sybtbl    = (Elf32_Sym*)&file_container[p_shead[i].sh_offset];     
                //num_sys     = p_shead[i].sh_size / p_shead[i].sh_entsize;
                //p_str_tbl2  = (char *)&file_container[p_shead[p_shead[i].sh_link].sh_offset];    // name of symbol table

                p_sybtbl    = reinterpret_cast<Elf32_Sym*>(file_container.data() + p_shead[i].sh_offset);                   // name of section
                p_str_tbl2  = reinterpret_cast<const char*>(file_container.data() + p_shead[p_shead[i].sh_link].sh_offset); // name of symbol table

                //std::cout << "sym table found!" << i << std::endl;

                break;
            } 
        }
    }




private:
    //char                            *file_container;
    //int64_t                         file_bytes;





    std::vector<unsigned char>      file_container;

    Elf32_Ehdr                      *p_elf_head;

    Elf32_Shdr                      *p_shead;
    int32_t                         total_num_sec;


    Elf32_Sym                       *p_sybtbl;

    const char                      *p_str_tbl;         // name of section
    const char                      *p_str_tbl2;        // name of symbol




};


#if 0

void    init_elf_context(   char                    *p_elf_ary,
                            uint64_t                elf_ary_size,

                            struct elf_context      *p_elf_context)
{

    Elf32_Ehdr      elf_head;
    uint32_t        i, j, k;

    memset((void*)p_elf_context,0,sizeof(struct elf_context));

    memcpy((void *)&elf_head, (void *)&p_elf_ary[0], sizeof(Elf32_Ehdr));

    Elf32_Shdr *p_shead = (Elf32_Shdr *)&p_elf_ary[elf_head.e_shoff];
    
    char *p_str_tbl = (char *)&p_elf_ary[p_shead[elf_head.e_shstrndx].sh_offset];   // name of section
    char *p_str_tbl2 = nullptr;

    Elf32_Sym   *p_sybtbl   = nullptr;
    uint32_t    num_sys     = 0;
 
    
    //---------------------------------------------------------------------------------------------
    //
    //
    //
    //
    //
    //---------------------------------------------------------------------------------------------
    for (i = 0; i < elf_head.e_shnum; i++)
    {
        if (SHT_SYMTAB == p_shead[i].sh_type)
        {
            p_sybtbl    = (Elf32_Sym*)&p_elf_ary[p_shead[i].sh_offset];     
            num_sys     = p_shead[i].sh_size / p_shead[i].sh_entsize;
            p_str_tbl2  = (char *)&p_elf_ary[p_shead[p_shead[i].sh_link].sh_offset];    // name of symbol table
            break;
        } 
    }

    p_elf_context->p_elf_ary                = p_elf_ary;
    p_elf_context->elf_bytes                = elf_ary_size;
    p_elf_context->elf_head                 = elf_head;
    p_elf_context->p_shead                  = p_shead;
    p_elf_context->total_num_sec            = elf_head.e_shnum;
    p_elf_context->p_sybtbl                 = p_sybtbl;
    p_elf_context->p_str_tbl                = p_str_tbl;
    p_elf_context->p_str_tbl2               = p_str_tbl2;

    //-----------------------------------------------------------------------------------
    // Description:
    //
    //
    //
    //-----------------------------------------------------------------------------------    
    p_elf_context->p_shead_info             = (struct section_info*)malloc(sizeof(struct section_info) * elf_head.e_shnum);

    memset((void*)p_elf_context->p_shead_info,0,elf_head.e_shnum*sizeof(struct section_info));

    //-----------------------------------------------------------------------------------
    // Description:
    //
    //
    //
    //-----------------------------------------------------------------------------------

    struct section_info * const p_sinfo = p_elf_context->p_shead_info;

    for (i = 0; i < elf_head.e_shnum; i++)
    {
        if(p_shead[i].sh_flags & SHF_ALLOC)
        {
            p_sinfo[i].dev_addr_origin      = p_shead[i].sh_addr;
            p_sinfo[i].elf_offset           = p_shead[i].sh_offset;
            p_sinfo[i].sec_bytes            = p_shead[i].sh_size;

            p_sinfo[i].sec_attr             = p_shead[i].sh_flags & SHF_WRITE ? SECTION_FOR_RW : SECTION_FOR_RO_X; 


        }
        else
        {
            p_sinfo[i].sec_attr             = SECTION_FOR_NO_DEV;
        }
        
    }



}
#endif









class instruction_bulk
{
    
public:

    instruction_bulk(void *ptr) {this->ptr = ptr;}

private:
    void            *ptr;

};








}       // namespace elf_parser

#endif  // end of __ELF__PRASER_H_____