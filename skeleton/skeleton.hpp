/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <eoslib/string.hpp>

namespace skeleton {

    struct PACKED(registercar) {
        eosio::string serial;
        eosio::string brand;
        eosio::string color;
        uint8_t body_type;
				time registdate;
    };

}/// skeleton
