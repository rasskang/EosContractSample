/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <eoslib/eos.hpp>

#include "skeleton.hpp"
#include "skeleton.gen.hpp"

namespace skeleton{

	void apply_registercar( const registercar& car ) {
		eosio::print( "\n\n", car.brand, "\n\n" );
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
		eosio::print( "Init car rent contract\n" );
	}

	/// The apply method implements the dispatch of events to this contract
	void apply( uint64_t code, uint64_t action ) {
		eosio::print( "Receive message: ", eosio::name(code), "->", eosio::name(action), "\n" );

		if(code==N(test)){
			if(action==N(registercar)){
				auto acm = eosio::current_message<skeleton::registercar>();
				eosio::print("\nAdd car message\n");
				eosio::dump(acm, 4);

				skeleton::apply_registercar( eosio::current_message<skeleton::registercar>() );
			}
		}
	}

} // extern "C"
