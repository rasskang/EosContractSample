/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <eoslib/eos.hpp>

#include "skeleton.hpp"
#include "skeleton.gen.hpp"

namespace skeleton {

	void apply_regist( const userinfo& user ) {
		eosio::print( "userinfo.email=>[", user.email, "]\n\n" );
	}

}

/**
 *  The init() and apply() methods must have C calling convention so that the blockchain can lookup and
 *  call these methods.
 */
extern "C" {

	/**
	 *  This method is called once when the contract is published or updated.
	 */
	void init()  {
		eosio::print( "Init skeleton contract\n" );
	}

	/// The apply method implements the dispatch of events to this contract
	void apply( uint64_t code, uint64_t action ) {
		eosio::print( "Receive message: ", eosio::name(code), "->", eosio::name(action), "\n" );

		if(code==N(test)){
			if(action==N(regist)){
				auto acm = eosio::current_message<skeleton::userinfo>();
				eosio::print("\nRegist skeleton message\n");
				eosio::dump(acm, 4);

				/*
				eosc -v push message test regist \
				'{"email" : "rasskang", "homepage" : "http://rasskang.tistory.com", "country" : "Korea", "birthyear" : 1978, "gender" : 1, "registdate" : "2018-02-23T15:21:59" }' \
				-S test
				*/
				skeleton::apply_regist( eosio::current_message<skeleton::userinfo>() );
			}
		}
	}

} // extern "C"
