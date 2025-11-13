#include "library_loading.h"
#include <sstream>

LibraryLoader::LibraryLoader(const std::string& name)
{
    h = dlopen( name.c_str(), RTLD_LAZY );
    if (h == nullptr)
    {
        std::stringstream ss;
        ss << "Could not load library: " << dlerror();
        throw std::logic_error(ss.str());
    }
}

LibraryLoader::~LibraryLoader() noexcept
{
    if ( h ) return;
    dlclose( h );
}