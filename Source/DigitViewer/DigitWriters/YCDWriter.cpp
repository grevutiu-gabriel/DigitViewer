/* YCDWriter.cpp
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 07/29/2013
 * Last Modified    : 07/29/2013
 * 
 */

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include "PublicLibs/CompilerSettings.h"
#include "PublicLibs/AlignedMalloc.h"
#include "PublicLibs/Exception.h"
#include "DigitViewer/Globals.h"
#include "DigitViewer/DigitReaders/YCDReader.h"
#include "YCDFileWriter.h"
#include "YCDWriter.h"
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
namespace DigitViewer{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Helpers
std::string YCDWriter::make_filename(uiL_t fileid){
    std::string full_path(path);
    full_path += name;
    full_path += " - ";
    full_path += std::to_string(fileid);
    full_path += ".ycd";
    return full_path;
}
void YCDWriter::create_file(uiL_t fileid){
    file = YCDFileWriter(
        make_filename(fileid),
        first_digits,
        digits_per_file,
        fileid,
        radix
    );
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
YCDWriter::YCDWriter(
    std::string path_,
    std::string name_,
    std::string first_digits,
    ufL_t digits_per_file_,
    uiL_t start_fileid,
    int radix_,
    upL_t buffer_size,
    u64_t* buffer,
    void (*deallocator)(void*)
)
    : path(std::move(path_))
    , name(std::move(name_))
    , radix(radix_)
    , start_fileid(start_fileid)
    , first_digits(std::move(first_digits))
    , digits_per_file(digits_per_file_)
    , fileid(start_fileid)
    , fp_free(deallocator)
{
    if (buffer_size < 4096)
        throw ym_exception("Requested buffer size is too small.", YCR_DIO_ERROR_INVALID_PARAMETERS);

    switch (radix){
        case 16: break;
        case 10: break;
        default:
            throw ym_exception("Unsupported Radix", YCR_DIO_ERROR_INVALID_BASE);
    }

    //  Make sure path ends in a slash.
    if (path.size() != 0){
        char back = path.back();
        if (back != '/' && back != '\\')
            path += '/';
    }

    //  Multiple files, create a folder for them.
    if (digits_per_file != (uiL_t)0 - 1){
        path += name;
        path += '/';
        FileIO::MakeDirectory(path.c_str());
    }

    bin_buffer_L = buffer_size / sizeof(u64_t);
    if (buffer == nullptr){
        external_buffer = false;
        bin_buffer = (u64_t*)AlignedMalloc(bin_buffer_L * sizeof(u64_t), 2*sizeof(u64_t));
    }else{
        external_buffer = true;
        bin_buffer = buffer;
    }
}
void YCDWriter::free_buffer(){
    if (bin_buffer == nullptr){
        return;
    }

    //  Internally allocated.
    if (!external_buffer)
        AlignedFree(bin_buffer);

    //  Preallocated with manual deallocator.
    if (fp_free != nullptr)
        fp_free(bin_buffer);

    bin_buffer = nullptr;
}
YCDWriter::~YCDWriter(){
    flush_buffer();
    free_buffer();
}
std::unique_ptr<DigitReader> YCDWriter::close_and_get_reader(upL_t buffer_size){
    flush_buffer();
    free_buffer();
    file.close();
    return std::make_unique<YCDReader>(make_filename(start_fileid), false, buffer_size);
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void YCDWriter::write(char* str, upL_t digits){
    while (true){
        //  No file is opened.
        if (!file.isValid()){
            create_file(fileid++);
        }

        //  Write digits
        upL_t written = file.write_chars(str, digits, bin_buffer, bin_buffer_L);
        if (written == digits)
            return;

        digits -= written;
        str    += written;
    }
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
