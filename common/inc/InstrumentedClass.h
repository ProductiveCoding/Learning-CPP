#pragma once

#include <iostream>

#define CE constexpr // Clang doesn't like this, but GCC is okay with it
#define NE noexcept

struct InstrumentedClass {
    CE InstrumentedClass() NE { puts("Default-constructor"); }
    CE InstrumentedClass(const InstrumentedClass&) NE { puts("Copy-constructor"); }
    CE InstrumentedClass(InstrumentedClass&&) NE { puts("Move-constructor"); }
    CE InstrumentedClass& operator=(const InstrumentedClass&) NE
    {
        puts("Copy-assignment"); return *this;
    }
    CE InstrumentedClass& operator=(InstrumentedClass&&) NE
    {
        puts("Move-assignment"); return *this;
    }
    ~InstrumentedClass() NE = default; // non-trivial dtor makes a class non-literal
};

