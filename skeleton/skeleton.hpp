/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <eoslib/string.hpp>

namespace skeleton {

	struct PACKED(userinfo) {
		eosio::string email;
		eosio::string homepage;
		eosio::string country;
		uint16_t birthyear;
		uint8_t gender;
		time registdate;
	};

}/// skeleton
