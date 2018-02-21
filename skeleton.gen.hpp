#pragma once

#include <eoslib/types.hpp>
#include <eoslib/message.hpp>
#include <eoslib/datastream.hpp>
#include <eoslib/raw_fwd.hpp>

//using namespace skeleton;

namespace eosio { namespace raw {
   template<typename Stream> inline void pack( Stream& s, const skeleton::registercar& value ) {
      raw::pack(s, value.serial);
      raw::pack(s, value.brand);
      raw::pack(s, value.color);
      raw::pack(s, value.registdate);
   }
   template<typename Stream> inline void unpack( Stream& s, skeleton::registercar& value ) {
      raw::unpack(s, value.serial);
      raw::unpack(s, value.brand);
      raw::unpack(s, value.color);
      raw::unpack(s, value.body_type);
      raw::unpack(s, value.registdate);
   }
} }

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

   void dump(const skeleton::registercar& value, int tab=0) {
      print_ident(tab);print("serial:[");prints_l(value.serial.get_data(), value.serial.get_size());print("]\n");
      print_ident(tab);print("brand:[");prints_l(value.brand.get_data(), value.brand.get_size());print("]\n");
      print_ident(tab);print("color:[");prints_l(value.color.get_data(), value.color.get_size());print("]\n");
      print_ident(tab);print("body_type:[");printi(uint8_t(value.body_type));print("]\n");
      print_ident(tab);print("registdate:[");printi(uint32_t(value.registdate));print("]\n");
   }

	template<>
	skeleton::registercar current_message<skeleton::registercar>() {
		return current_message_ex<skeleton::registercar>();
	}

} ///eosio

