/* i couldn't find this online so i had to make it myself */

#include "top.h"
#include "toolkit.h"

void main( int ArgC, char** Args )
{

	CToolkit * Toolkit = new CToolkit( Args[ 1 ] );

	unsigned char* Bytes = Toolkit->DumpBytes( 0 );

	printf( "byte %s[ %d ] = \n{ ", Toolkit->_Arrayname, Toolkit->Filesize );

	for ( int i = 0; i < Toolkit->Filesize; ++i )
	{
		/* fix newline */
		if ( !( i % 22 ) )
		{
			printf( "\n" );
		}		

		printf( "0x" );

		/* fix single char values */
		if ( Bytes[ i ] < 16 )
		{
			printf( "0" );
		}

		/* print dem bytes */
		printf( "%X", Bytes[ i ] );

		/* separate bytes */
		if ( i < Toolkit->Filesize - 1 )
		{
			printf( "," );
		}
	}

	printf( "\n};" );

	getchar( );
}
