/* u32d9_forward_intrinsics_Default.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 01/22/2011
 * Last Modified    : 01/23/2016
 * 
 */

#ifndef ydv_u32d9_forward_intrinsics_Default_H
#define ydv_u32d9_forward_intrinsics_Default_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#include "PublicLibs/CompilerSettings.h"
#include "PublicLibs/Types.h"
namespace DigitViewer{
namespace u32d9{
    using namespace ymp;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Iterate Reverse, Raw Output
YM_FORCE_INLINE void convert_d9x1_forward_Default(char str[9], u32_t dec){
    u32_t r0 = dec;

    str[8] = (char)(r0 % 10);
    r0 /= 10;
    str[7] = (char)(r0 % 10);
    r0 /= 10;
    str[6] = (char)(r0 % 10);
    r0 /= 10;
    str[5] = (char)(r0 % 10);
    r0 /= 10;
    str[4] = (char)(r0 % 10);
    r0 /= 10;
    str[3] = (char)(r0 % 10);
    r0 /= 10;
    str[2] = (char)(r0 % 10);
    r0 /= 10;
    str[1] = (char)(r0 % 10);
    r0 /= 10;
    str[0] = (char)r0;
}
YM_FORCE_INLINE void convert_d9x2_forward_Default(char str[9*2], const u32_t dec[2]){
    u32_t r0 = dec[0];
    u32_t r1 = dec[1];

    str[17] = (char)(r0 % 10);
    str[ 8] = (char)(r1 % 10);
    r0 /= 10;
    r1 /= 10;
    str[16] = (char)(r0 % 10);
    str[ 7] = (char)(r1 % 10);
    r0 /= 10;
    r1 /= 10;
    str[15] = (char)(r0 % 10);
    str[ 6] = (char)(r1 % 10);
    r0 /= 10;
    r1 /= 10;
    str[14] = (char)(r0 % 10);
    str[ 5] = (char)(r1 % 10);
    r0 /= 10;
    r1 /= 10;
    str[13] = (char)(r0 % 10);
    str[ 4] = (char)(r1 % 10);
    r0 /= 10;
    r1 /= 10;
    str[12] = (char)(r0 % 10);
    str[ 3] = (char)(r1 % 10);
    r0 /= 10;
    r1 /= 10;
    str[11] = (char)(r0 % 10);
    str[ 2] = (char)(r1 % 10);
    r0 /= 10;
    r1 /= 10;
    str[10] = (char)(r0 % 10);
    str[ 1] = (char)(r1 % 10);
    r0 /= 10;
    r1 /= 10;
    str[ 9] = (char)r0;
    str[ 0] = (char)r1;
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
}
#endif
