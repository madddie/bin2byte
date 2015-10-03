#pragma once

#include "top.h"

class CToolkit
{
public:

	char	_PathToFile[ FILENAME_MAX + 1 ];

	char*	_Arrayname;

	FILE*	_File;

	size_t	Filesize;

	CToolkit( char* PathToFile )
	{
		memcpy( _PathToFile, PathToFile, FILENAME_MAX );

		_File = fopen( PathToFile, "rb" );

		_Arrayname = GetFilename( PathToFile );

		Filesize = GetSize( );
	}

	size_t GetSize( )
	{
		FILE* TempFile = fopen( _PathToFile, "rb" );

		fseek( TempFile, 0, SEEK_END );

		size_t FileSize = ftell( TempFile );

		rewind( TempFile );

		fclose( TempFile );

		return FileSize;
	}

	char* GetFilename( char* Path )
	{
		int Len = strlen( Path );

		while ( Path[ Len ] != '\\' )
		{
			Len--;
		}

		return &Path[ Len + 1 ];
	}

	unsigned char* DumpBytes( bool ToClipboard )
	{
		unsigned char* Bytes = new unsigned char[ Filesize + 1 ];
	
		fread( Bytes, 1, Filesize, _File );

		return Bytes;
	}
};