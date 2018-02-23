#pragma once

#include <eoslib/types.hpp>
#include <eoslib/message.hpp>
#include <eoslib/datastream.hpp>
#include <eoslib/raw_fwd.hpp>

//using namespace skeleton;

namespace eosio { namespace raw {
	template<typename Stream> inline void pack( Stream& s, const skeleton::userinfo& value ) {
		raw::pack(s, value.email);
		raw::pack(s, value.homepage);
		raw::pack(s, value.country);
		raw::pack(s, value.birthyear);
		raw::pack(s, value.gender);
		raw::pack(s, value.registdate);
	}
	template<typename Stream> inline void unpack( Stream& s, skeleton::userinfo& value ) {
		raw::unpack(s, value.email);
		raw::unpack(s, value.homepage);
		raw::unpack(s, value.country);
		raw::unpack(s, value.birthyear);
		raw::unpack(s, value.gender);
		raw::unpack(s, value.registdate);
	}
} } ///eosio::raw

#include <eoslib/raw.hpp>
namespace eosio {

	void print_ident(int n){while(n-->0){print("  ");}};

	template<typename Type>
		Type current_message_ex() {
			uint32_t size = message_size();
			char* data = (char *)eosio::malloc(size);
			assert(data && read_message(data, size) == size, "error reading message");
			Type value;
			eosio::raw::unpack(data, size, value);
			eosio::free(data);
			return value;
		}

	void dump(const skeleton::userinfo& value, int tab=0) {
		print_ident(tab);print("email:[");prints_l(value.email.get_data(), value.email.get_size());print("]\n");
		print_ident(tab);print("homepage:[");prints_l(value.homepage.get_data(), value.homepage.get_size());print("]\n");
		print_ident(tab);print("country:[");prints_l(value.country.get_data(), value.country.get_size());print("]\n");
		print_ident(tab);print("birthyear:[");printi(uint16_t(value.birthyear));print("]\n");
		print_ident(tab);print("gender:[");printi(uint8_t(value.gender));print("]\n");
		print_ident(tab);print("registdate:[");printi(uint32_t(value.registdate));print("]\n");
	}

	template<>
		skeleton::userinfo current_message<skeleton::userinfo>() {
			return current_message_ex<skeleton::userinfo>();
		}

} ///eosio

