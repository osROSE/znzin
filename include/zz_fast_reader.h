/** 
 * @file zz_fast_reader.h
 * @brief class for quickly reading from files
 * @author Brett Lawson (brett19@gmail.com)
 * @version 1.0
 * @date 25-jan-2011
 */

#ifndef __ZZ_FAST_READER_H__
#define __ZZ_FAST_READER_H__

#ifndef	__ZZ_VFS_H__
#include "zz_vfs.h"
#endif

class zz_fast_reader {
protected:
	char* data_;
	char* cursor_;

public:
	zz_fast_reader( ) : data_(NULL), cursor_(NULL) {
	}

	~zz_fast_reader( ) {
		unload( );
	}

	bool load( zz_vfs& vfs, uint32 size ) {
		unload();
		if( size == 0 ) return true;
		data_ = zz_new char[ size ];
		if( vfs.read( data_, size ) != size ) {
			zz_delete data_;
			data_ = cursor_ = NULL;
			assert(!"not enough data in the file");
			return false;
		}
		cursor_ = data_;
		return true;
	}

	void unload( ) {
		ZZ_SAFE_DELETE(data_);
		cursor_ = 0;
	}
	
	inline void read_char (char& data_out) { data_out = *(*(reinterpret_cast<char**>(&cursor_)))++; }
	inline void  read_uchar (uchar& data_out) { data_out = *(*(reinterpret_cast<uchar**>(&cursor_)))++; }
	inline void  read_float (float& data_out) { data_out = *(*(reinterpret_cast<float**>(&cursor_)))++; }

	inline void  read_uint32 (uint32& data_out) { data_out = *(*(reinterpret_cast<uint32**>(&cursor_)))++; }
	inline void  read_uint32 (int& data_out) { data_out = *(*(reinterpret_cast<int**>(&cursor_)))++; }
	inline void  read_uint16 (uint16& data_out) { data_out = *(*(reinterpret_cast<uint16**>(&cursor_)))++; }
	inline void  read_int16 (int16& data_out) { data_out = *(*(reinterpret_cast<int16**>(&cursor_)))++; }
	inline void  read_int32 (int32& data_out) { data_out = *(*(reinterpret_cast<int32**>(&cursor_)))++; }

};

#endif //__ZZ_FAST_READER_H__