#include "utils/smdh.hpp"

#include <3ds.h>
#include <string>

std::u16string UTF8toUTF16(const char* src);
std::string UTF16toUTF8(const std::u16string& src);
std::string format(std::string fmt_str, ...);
std::string timeStr(void);
