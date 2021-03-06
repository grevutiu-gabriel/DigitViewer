/* AlignedMalloc.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 01/25/2015
 * Last Modified    : 01/25/2015
 * 
 */

#pragma once
#ifndef ymp_Memory_AlignedMalloc_H
#define ymp_Memory_AlignedMalloc_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include "PublicLibs/Types.h"
namespace ymp{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
const upL_t DEFAULT_ALIGNMENT = 64;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void* AlignedMalloc(upL_t bytes, upL_t align = DEFAULT_ALIGNMENT);
void AlignedFree(void *ptr);
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
