
/*
 *  utility.h
 *
 *  Created on: 2025-11-14
 *      Author: mingyanq
 */

#ifndef __UTILITYH____H______
#define __UTILITYH____H______

#include <stdint.h>

#include <cstdint>
#include <iostream>
#include <vector>

namespace elf_parser
{

template<
    int         _numbits
>
class micro_code
{
public:

    static int const numbits    = _numbits;
    static int const nbytes     = (_numbits+0x07)>>3;

    micro_code(void)
    {
        for(int i = 0; i < nbytes; i++) 
        {
            _code[i] = 0;
        }
    }

    micro_code(void *_ptr)
    {
        char    *ptr    = (char*)_ptr;

        for(int i = 0; i < nbytes; i++) 
        {
            _code[i] = ptr[i];
        }
    }

    micro_code(std::vector<int>  vpos)
    {
        for(int i = 0; i < nbytes; i++) 
        {
            _code[i] = 0;
        }

        for(auto pos:vpos)
        {
            if(pos < numbits)
            {
                _code[pos>>3] |= 1<<(pos&0x07);
            }
            
        }

    }


    template <typename T>
    T       gather_bits(std::vector<int> &vindex,bool sig_ext=true)
    {
        T   val = 0;


        for(auto idx:vindex)
        {
            if(idx < numbits)
            {
                if(val&1)
                {
                    _code[idx>>3]   |= 1<<(idx&0x07);  
                }
                else
                {
                    _code[idx>>3]   &= ~(1<<(idx&0x07));  
                }

                val >>= 1;
                
            }

        }

        return val;
    }

    template <typename T>
    void    scatter_bits(std::vector<int> &vindex,T val)
    {
        for(auto idx:vindex)
        {
            if(idx < numbits)
            {
                if(val&1)
                {
                    _code[idx>>3]   |= 1<<(idx&0x07);  
                }
                else
                {
                    _code[idx>>3]   &= ~(1<<(idx&0x07));  
                }

                val >>= 1;
                
            }

        }
    }

    void print(void)
    {
        for(int i = 0; i < nbytes; i++) 
        {
            printf("0x%x ",_code[i]);
        }
        printf("\n");
    }

    micro_code operator&(const micro_code &input) const
    {
        class micro_code res;

        for(int i = 0; i < nbytes; i++) 
        {
            res._code[i]    = _code[i]&input._code[i];
        }

        return res;
    }

    micro_code operator&(const uint32_t input) const
    {
        class micro_code res;

        char *pin = (char*)&input;

        for(int i = 0; i < nbytes; i++) 
        {
            res._code[i]    = i < sizeof(input) ? _code[i] & pin[i] : 0;
        }

        return res;
    }

    micro_code operator&(const uint64_t input) const
    {
        class micro_code res;

        char *pin = (char*)&input;

        for(int i = 0; i < nbytes; i++) 
        {
            res._code[i]    = i < sizeof(input) ? _code[i] & pin[i] : 0;
        }

        return res;
    }
    
    
    micro_code operator|(const micro_code &input) const
    {
        class micro_code res;

        for(int i = 0; i < nbytes; i++) 
        {
            res._code[i]    = _code[i]|input._code[i];
        }

        return res;
    }
    
    micro_code operator^(const micro_code &input) const
    {
        class micro_code res;

        for(int i = 0; i < nbytes; i++) 
        {
            res._code[i]    = _code[i]^input._code[i];
        }

        return res;
    }    

    bool operator==(const micro_code &input) const
    {
        for(int i = 0; i < nbytes; i++) 
        {
            if(_code[i]!=input._code[i])
            {
                return false;
            }
        }
        return true;
    }
 
private:
    char    _code[nbytes];

};



}
#endif
