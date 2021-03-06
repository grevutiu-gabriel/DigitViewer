/* u32d9_forward_convert_Default.ipp
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 01/20/2011
 * Last Modified    : 01/23/2016
 * 
 */

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#include "u32d9_forward_intrinsics_Default.h"
#include "u32d9.h"
namespace DigitViewer{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void u32r_to_d9r(char* T, const u32_t* A, upL_t AL){
    T += AL * 9;
    const u32_t* stopA = A + AL - 1;

    while (A < stopA){
        T -= 18;
        u32d9::convert_d9x2_forward_Default(T, A);
        A += 2;
    }
    if (A < stopA + 1){
        T -= 9;
        u32d9::convert_d9x1_forward_Default(T, *A);
        A += 1;
    }
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
