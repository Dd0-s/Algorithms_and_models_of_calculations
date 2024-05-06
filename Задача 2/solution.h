#pragma once

#include <stdexcept>
#include "fake_crypto.h"

std::tuple<vector_t, vector_t, vector_t> FakeSign(const std::string &message, RWEPublicKey public_key) {
    vector_t c = {};
    vector_t z1 = {};
    vector_t z2 = {};
    auto message_hash = ComputeSimpleHash(message);
    auto module = public_key.getModule();
    auto ase_vector = public_key.getASEVector();
    auto a_vector = public_key.getAVector();
    for (int & i : c){
        i = 0;
    }
    for(int & i : z1){
       i = module;
    }
    for(int i = 0; i < z2.size(); i++){
        if(message_hash[i] != 0){
            z2[i] = -message_hash[i];
        }
        else{
            z2[i] = -message_hash[i] + module;
        }
    }
    return std::make_tuple(c, z1, z2);
}