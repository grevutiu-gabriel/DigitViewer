/* AlignedMalloc.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 01/25/2015
 * Last Modified    : 01/25/2015
 * 
 */

#pragma once
#ifndef _ymp_AlignedMalloc_H
#define _ymp_AlignedMalloc_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <stdlib.h>
#include "Types.h"
namespace ymp{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
inline void* AlignedMalloc(upL_t bytes,upL_t align){
    if (align < sizeof(upL_t))
        align = sizeof(upL_t);

    void *ptr = malloc((size_t)(bytes + align + sizeof(upL_t)));
    if (ptr == nullptr){
        return nullptr;
    }

    upL_t *ret = (upL_t*)((((upL_t)ptr + sizeof(upL_t)) & ~(upL_t)(align - 1)) + align);

    ret[-1] = (upL_t)ptr;

    return ret;
}
inline void AlignedFree(void *ptr){
    if (ptr == nullptr)
        return;

    ptr = (void*)(((upL_t*)ptr)[-1]);

    free(ptr);
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif