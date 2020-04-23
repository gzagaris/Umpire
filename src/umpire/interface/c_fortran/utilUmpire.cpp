// utilUmpire.cpp
// This file is generated by Shroud 0.11.0. Do not edit.
// Copyright (c) 2016-20, Lawrence Livermore National Security, LLC and Umpire
// project contributors. See the COPYRIGHT file for details.
//
// SPDX-License-Identifier: (MIT)
#include "typesUmpire.h"

#include <cstddef>
#include <cstring>


#ifdef __cplusplus
extern "C" {
#endif

// helper copy_string
// Copy the char* or std::string in context into c_var.
// Called by Fortran to deal with allocatable character.
void umpire_ShroudCopyStringAndFree(umpire_SHROUD_array *data, char *c_var, size_t c_var_len) {
    const char *cxx_var = data->addr.ccharp;
    size_t n = c_var_len;
    if (data->elem_len < n) n = data->elem_len;
    std::strncpy(c_var, cxx_var, n);
    umpire_SHROUD_memory_destructor(&data->cxx); // delete data->cxx.addr
}


#ifdef __cplusplus
}
#endif
