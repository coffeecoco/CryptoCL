#include "AES/RoundKeyTest.h"

#include <sstream>
#include <iostream>

#include <CryptoCL/AES/RoundKey.h>
#include <cppunit/extensions/HelperMacros.h>

CPPUNIT_TEST_SUITE_REGISTRATION( AES::RoundKeyTest );

namespace AES {
	using namespace CryptoCL::AES;
	
	// 128 Bit Tests
	void RoundKeyTest::testBitSize128() {
		const unsigned char key[] = { 
			0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f
		};
		
		const RoundKey rKey( std::vector<unsigned char>( key, key + 16 ) );
		
		CPPUNIT_ASSERT_EQUAL( (int)Key::Bit128, (int)rKey.Size() );
	}
	
	void RoundKeyTest::testRoundCount128() {
		const unsigned char key[] = { 
			0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f
		};
		
		const RoundKey rKey( std::vector<unsigned char>( key, key + 16 ) );
		
		CPPUNIT_ASSERT_EQUAL( (int)10, (int)rKey.Rounds() );
	}
	
	void RoundKeyTest::testGenerate128() {
		const unsigned char key[] = { 
			0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f
		};

		const unsigned char expected[] = {
			0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
			0xd6,0xaa,0x74,0xfd,0xd2,0xaf,0x72,0xfa,0xda,0xa6,0x78,0xf1,0xd6,0xab,0x76,0xfe,
			0xb6,0x92,0xcf,0x0b,0x64,0x3d,0xbd,0xf1,0xbe,0x9b,0xc5,0x00,0x68,0x30,0xb3,0xfe,
			0xb6,0xff,0x74,0x4e,0xd2,0xc2,0xc9,0xbf,0x6c,0x59,0x0c,0xbf,0x04,0x69,0xbf,0x41,
			0x47,0xf7,0xf7,0xbc,0x95,0x35,0x3e,0x03,0xf9,0x6c,0x32,0xbc,0xfd,0x05,0x8d,0xfd,
			0x3c,0xaa,0xa3,0xe8,0xa9,0x9f,0x9d,0xeb,0x50,0xf3,0xaf,0x57,0xad,0xf6,0x22,0xaa,
			0x5e,0x39,0x0f,0x7d,0xf7,0xa6,0x92,0x96,0xa7,0x55,0x3d,0xc1,0x0a,0xa3,0x1f,0x6b,
			0x14,0xf9,0x70,0x1a,0xe3,0x5f,0xe2,0x8c,0x44,0x0a,0xdf,0x4d,0x4e,0xa9,0xc0,0x26,
			0x47,0x43,0x87,0x35,0xa4,0x1c,0x65,0xb9,0xe0,0x16,0xba,0xf4,0xae,0xbf,0x7a,0xd2,
			0x54,0x99,0x32,0xd1,0xf0,0x85,0x57,0x68,0x10,0x93,0xed,0x9c,0xbe,0x2c,0x97,0x4e,
			0x13,0x11,0x1d,0x7f,0xe3,0x94,0x4a,0x17,0xf3,0x07,0xa7,0x8b,0x4d,0x2b,0x30,0xc5
		};
		
		const RoundKey rKey( std::vector<unsigned char>( key, key + 16 ) );
		const std::vector<unsigned char> result = rKey.Value();
		
		const unsigned int keySize = result.size();
		CPPUNIT_ASSERT_EQUAL( 176, (int)keySize );
		
		for( unsigned int i = 0; i < keySize; i++ ){
			std::ostringstream stream;
			stream << "Element " << i << " Differs";
			
			CPPUNIT_ASSERT_EQUAL_MESSAGE( stream.str(), (int)expected[i], (int)result[i] );
		}
	}
	
	// 192 Bit Tests
	void RoundKeyTest::testBitSize192() {
		const unsigned char key[] = { 
			0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
			0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17
		};
		
		const RoundKey rKey( std::vector<unsigned char>( key, key + 24 ) );
		
		CPPUNIT_ASSERT_EQUAL( (int)Key::Bit192, (int)rKey.Size() );
	}
	
	void RoundKeyTest::testRoundCount192() {
		const unsigned char key[] = { 
			0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
			0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17 
		};
		
		const RoundKey rKey( std::vector<unsigned char>( key, key + 24 ) );
		
		CPPUNIT_ASSERT_EQUAL( (int)12, (int)rKey.Rounds() );
	}
	
	void RoundKeyTest::testGenerate192() {
		const unsigned char key[] = { 
			0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
			0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17
		};

		const unsigned char expected[] = {
			0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
			0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x58,0x46,0xf2,0xf9,0x5c,0x43,0xf4,0xfe,
			0x54,0x4a,0xfe,0xf5,0x58,0x47,0xf0,0xfa,0x48,0x56,0xe2,0xe9,0x5c,0x43,0xf4,0xfe,
			0x40,0xf9,0x49,0xb3,0x1c,0xba,0xbd,0x4d,0x48,0xf0,0x43,0xb8,0x10,0xb7,0xb3,0x42,
			0x58,0xe1,0x51,0xab,0x04,0xa2,0xa5,0x55,0x7e,0xff,0xb5,0x41,0x62,0x45,0x08,0x0c,
			0x2a,0xb5,0x4b,0xb4,0x3a,0x02,0xf8,0xf6,0x62,0xe3,0xa9,0x5d,0x66,0x41,0x0c,0x08,
			0xf5,0x01,0x85,0x72,0x97,0x44,0x8d,0x7e,0xbd,0xf1,0xc6,0xca,0x87,0xf3,0x3e,0x3c,
			0xe5,0x10,0x97,0x61,0x83,0x51,0x9b,0x69,0x34,0x15,0x7c,0x9e,0xa3,0x51,0xf1,0xe0,
			0x1e,0xa0,0x37,0x2a,0x99,0x53,0x09,0x16,0x7c,0x43,0x9e,0x77,0xff,0x12,0x05,0x1e,
			0xdd,0x7e,0x0e,0x88,0x7e,0x2f,0xff,0x68,0x60,0x8f,0xc8,0x42,0xf9,0xdc,0xc1,0x54,
			0x85,0x9f,0x5f,0x23,0x7a,0x8d,0x5a,0x3d,0xc0,0xc0,0x29,0x52,0xbe,0xef,0xd6,0x3a,
			0xde,0x60,0x1e,0x78,0x27,0xbc,0xdf,0x2c,0xa2,0x23,0x80,0x0f,0xd8,0xae,0xda,0x32,
			0xa4,0x97,0x0a,0x33,0x1a,0x78,0xdc,0x09,0xc4,0x18,0xc2,0x71,0xe3,0xa4,0x1d,0x5d
		};
		
		const RoundKey rKey( std::vector<unsigned char>( key, key + 24 ) );
		const std::vector<unsigned char> result = rKey.Value();
		
		const unsigned int keySize = result.size();
		CPPUNIT_ASSERT_EQUAL( 208, (int)keySize );
		
		for( unsigned int i = 0; i < keySize; i++ ){
			std::ostringstream stream;
			stream << "Element " << i << " Differs";
			
			CPPUNIT_ASSERT_EQUAL_MESSAGE( stream.str(), (int)expected[i], (int)result[i] );
		}
	}
	
	// 256 Bit Tests
	void RoundKeyTest::testBitSize256() {
		const unsigned char key[] = { 
			0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
			0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f 
		};
		
		const RoundKey rKey( std::vector<unsigned char>( key, key + 32 ) );
		
		CPPUNIT_ASSERT_EQUAL( (int)Key::Bit256, (int)rKey.Size() );
	}
	
	
	void RoundKeyTest::testRoundCount256() {
		const unsigned char key[] = { 
			0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
			0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f 
		};
		
		const RoundKey rKey( std::vector<unsigned char>( key, key + 32 ) );
		
		CPPUNIT_ASSERT_EQUAL( (int)14, (int)rKey.Rounds() );
	}
	
	void RoundKeyTest::testGenerate256() {
		const unsigned char key[] = { 
			0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
			0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f 
		};
		
		const unsigned char expected[] = {
			0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 
			0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 
			0xa5, 0x73, 0xc2, 0x9f, 0xa1, 0x76, 0xc4, 0x98, 0xa9, 0x7f, 0xce, 0x93, 0xa5, 0x72, 0xc0, 0x9c, 
			0x16, 0x51, 0xa8, 0xcd, 0x02, 0x44, 0xbe, 0xda, 0x1a, 0x5d, 0xa4, 0xc1, 0x06, 0x40, 0xba, 0xde, 
			0xae, 0x87, 0xdf, 0xf0, 0x0f, 0xf1, 0x1b, 0x68, 0xa6, 0x8e, 0xd5, 0xfb, 0x03, 0xfc, 0x15, 0x67, 
			0x6d, 0xe1, 0xf1, 0x48, 0x6f, 0xa5, 0x4f, 0x92, 0x75, 0xf8, 0xeb, 0x53, 0x73, 0xb8, 0x51, 0x8d, 
			0xc6, 0x56, 0x82, 0x7f, 0xc9, 0xa7, 0x99, 0x17, 0x6f, 0x29, 0x4c, 0xec, 0x6c, 0xd5, 0x59, 0x8b, 
			0x3d, 0xe2, 0x3a, 0x75, 0x52, 0x47, 0x75, 0xe7, 0x27, 0xbf, 0x9e, 0xb4, 0x54, 0x07, 0xcf, 0x39, 
			0x0b, 0xdc, 0x90, 0x5f, 0xc2, 0x7b, 0x09, 0x48, 0xad, 0x52, 0x45, 0xa4, 0xc1, 0x87, 0x1c, 0x2f, 
			0x45, 0xf5, 0xa6, 0x60, 0x17, 0xb2, 0xd3, 0x87, 0x30, 0x0d, 0x4d, 0x33, 0x64, 0x0a, 0x82, 0x0a, 
			0x7c, 0xcf, 0xf7, 0x1c, 0xbe, 0xb4, 0xfe, 0x54, 0x13, 0xe6, 0xbb, 0xf0, 0xd2, 0x61, 0xa7, 0xdf, 
			0xf0, 0x1a, 0xfa, 0xfe, 0xe7, 0xa8, 0x29, 0x79, 0xd7, 0xa5, 0x64, 0x4a, 0xb3, 0xaf, 0xe6, 0x40, 
			0x25, 0x41, 0xfe, 0x71, 0x9b, 0xf5, 0x00, 0x25, 0x88, 0x13, 0xbb, 0xd5, 0x5a, 0x72, 0x1c, 0x0a, 
			0x4e, 0x5a, 0x66, 0x99, 0xa9, 0xf2, 0x4f, 0xe0, 0x7e, 0x57, 0x2b, 0xaa, 0xcd, 0xf8, 0xcd, 0xea, 
			0x24, 0xfc, 0x79, 0xcc, 0xbf, 0x09, 0x79, 0xe9, 0x37, 0x1a, 0xc2, 0x3c, 0x6d, 0x68, 0xde, 0x36
		};
		
		const RoundKey rKey( std::vector<unsigned char>( key, key + 32 ) );
		const std::vector<unsigned char> result = rKey.Value();
		
		const unsigned int keySize = result.size();
		CPPUNIT_ASSERT_EQUAL( 240, (int)keySize );
	
		for( unsigned int i = 0; i < keySize; i++ ){
			std::ostringstream stream;
			stream << "Element " << i << " Differs";
			
			CPPUNIT_ASSERT_EQUAL_MESSAGE( stream.str(), (int)expected[i], (int)result[i] );
		}
	}
}
