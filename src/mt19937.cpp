
#include "mt19937.hpp"

#include <random>
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>

namespace prngCpp {

MT19937::MT19937 ()
{
    //std::clog << "ctor MT19937" << std::endl;
    seeding();
}

MT19937::~MT19937()
{
    //std::clog << "dtor ~MT19937" << std::endl;
}

void MT19937::seeding()
{
    std::array<uint32_t, std::mt19937::state_size> _sdta;
    std::generate_n(_sdta.begin(), _sdta.size(), std::ref(_rd));
    std::seed_seq _seq(std::begin(_sdta), std::end(_sdta));
    _gen = std::mt19937(_seq);
    _init = true;
}

uint32_t MT19937::get_uint32()
{
    if (! _init) {
        throw "not yet initialized!";
    }
    uint32_t g = _gen();
    return (uint32_t)g;
}


} // namespace

#ifdef _WINDLL
#define DLLEXPORT __declspec( dllexport )
#else
#define DLLEXPORT 
#endif

extern "C" DLLEXPORT prngCpp::MT19937 * mk_mt19937()
{
	return new prngCpp::MT19937();
}

extern "C" DLLEXPORT uint32_t get_uint32(prngCpp::MT19937 * prng)
{
	return prng ? prng->get_uint32() : 0UL;
}

extern "C" DLLEXPORT void del_ptr(prngCpp::MT19937 * prng)
{
	if (prng) { delete prng; }
}

