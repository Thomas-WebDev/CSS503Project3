#include <fcntl.h>     // open
#include <sys/types.h> // read
#include <sys/uio.h>   // read
#include <unistd.h>    // read, close
#include <strings.h>   // bcopy
#include <string.h>    // strlen
#include <stdarg.h>    // format, ...
#include <stdlib.h>    // abs
#include "stdio.h"

using namespace std;

char decimal[100];

int recursive_itoa( int arg ) {
  int div = arg / 10;
  int mod = arg % 10;
  int index = 0;
  if ( div > 0 )
    index = recursive_itoa( div );
  decimal[index] = mod + '0';
  return ++index;
}

char *itoa( const int arg ) {
  bzero( decimal, 100 );
  int order = recursive_itoa( arg );
  char *new_decimal = new char[order + 1];
  bcopy( decimal, new_decimal, order + 1 );
  return new_decimal;
}

int printf( const void *format, ... ) {
  va_list list;
  va_start( list, format );

  char *msg = ( char * )format;
  char buf[1024];
  int nWritten = 0;

  int i = 0, j = 0, k = 0;
  while ( msg[i] != '\0') {
    if ( msg[i] == '%' && msg[i + 1] == 'd' ) {
      buf[j] = '\0';
      nWritten += write( 1, buf, j );
      j = 0;
      i += 2;

      int int_val = va_arg( list, int );
      char *dec = itoa( abs( int_val ) );
      if ( int_val < 0 )
	nWritten += write( 1, "-", 1 );
      nWritten += write( 1, dec, strlen( dec ) );
      delete dec;
    }
    else
      buf[j++] = msg[i++];
  }
  if ( j > 0 )
    nWritten += write( 1, buf, j );
  va_end( list );
}

int setvbuf( FILE *stream, char *buf, int mode, size_t size ) {
  if ( mode != _IONBF && mode != _IOLBF && mode != _IOFBF )
    return -1;
  stream->mode = mode;
  stream->pos = 0;

  if ( stream->buffer != (char *)0 && stream->bufown == true )
    delete stream->buffer;

  switch ( mode ) {
  case _IONBF:
    stream->buffer = (char *)0;
    stream->size = 0;
    stream->bufown = false;
    break;
  case _IOLBF:
  case _IOFBF:
    if ( buf != (char *)0 ) {
      stream->buffer = buf;
      stream->size   = size;
      stream->bufown = false;
    }
    else {
      stream->buffer = new char[BUFSIZ];
      stream->size = BUFSIZ;
      stream->bufown = true;
    }
    break;
  }
  
  return 0;
}

void setbuf( FILE *stream, char *buf ) {
  setvbuf( stream, buf, ( buf != (char *)0 ) ? _IOFBF : _IONBF , BUFSIZ );
}

FILE *fopen( const char *path, const char *mode ) {
  FILE *stream = new FILE( );
  setvbuf( stream, (char *)0, _IOFBF, BUFSIZ );

  // fopen( ) mode
  // r or rb           =  O_RDONLY
  // w or wb           =  O_WRONLY | O_CREAT | O_TRUNC
  // a or ab           =  O_WRONLY | O_CREAT | O_APPEND
  // r+ or rb+ or r+b  =  O_RDWR
  // w+ or wb+ or w+b  =  O_RDWR   | O_CREAT | O_TRUNC
  // a+ or ab+ or a+b  =  O_RDWR   | O_CREAT | O_APPEND

  switch( mode[0] ) {
  case 'r':
    if ( mode[1] == '\0' )            // r
      stream->flag = O_RDONLY;
    else if ( mode[1] == 'b' ) {    
      if ( mode[2] == '\0' )          // rb
	stream->flag = O_RDONLY;
      else if ( mode[2] == '+' )      // rb+
	stream->flag = O_RDWR;
    }
    else if ( mode[1] == '+' )        // r+  r+b
      stream->flag = O_RDWR;
    break;
  case 'w':
    if ( mode[1] == '\0' )            // w
      stream->flag = O_WRONLY | O_CREAT | O_TRUNC;
    else if ( mode[1] == 'b' ) {    
      if ( mode[2] == '\0' )          // wb
	stream->flag = O_WRONLY | O_CREAT | O_TRUNC;
      else if ( mode[2] == '+' )      // wb+
	stream->flag = O_RDWR | O_CREAT | O_TRUNC;
    }
    else if ( mode[1] == '+' )        // w+  w+b
      stream->flag = O_RDWR | O_CREAT | O_TRUNC;
    break;
  case 'a':
    if ( mode[1] == '\0' )            // a
      stream->flag = O_WRONLY | O_CREAT | O_APPEND;
    else if ( mode[1] == 'b' ) {    
      if ( mode[2] == '\0' )          // ab
	stream->flag = O_WRONLY | O_CREAT | O_APPEND;
      else if ( mode[2] == '+' )      // ab+
	stream->flag = O_RDWR | O_CREAT | O_APPEND;
    }
    else if ( mode[1] == '+' )        // a+  a+b
      stream->flag = O_RDWR | O_CREAT | O_APPEND;
    break;
  }

  mode_t open_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

  if ( ( stream->fd = open( path, stream->flag, open_mode ) ) == -1 ) {
    delete stream;
    printf( "fopen failed\n" );
    stream = NULL;
  }

  return stream;
}

int fpurge( FILE *stream ) {
  bzero(stream->buffer, stream->size);
  return 0;
}

int fflush( FILE *stream ) {
	if (stream->eof == true)
		return(EOF);
	write(stream->fd, stream->buffer, stream->size);
	bzero(stream->buffer, stream->size);
	stream->actual_size = 0;
	return 0;
}

size_t fread( void *ptr, size_t size, size_t nmemb, FILE *stream ) {
	char* buffer = (char*)ptr;
	size_t charRead = 0;
	int nRead = 1;
	while (charRead < nmemb && nRead > 0) { // 	while not eof
		// call read() size times to read the chars
		for (int i = 0; i <  size; ++i) {
			nRead = read(stream->fd, buffer, 1);
			if (nRead == 0)
				break;
		}
		if (nRead == 0 )
			stream->eof = true;
		else {
			buffer += size;
			++charRead;
		}
	}
	return charRead;
}

size_t fwrite( const void *ptr, size_t size, size_t nmemb, FILE *stream ) {
	if (size <= 0 || nmemb <= 0)
		return 0;
	if (stream->flag == O_RDONLY)
		return(0);
	if (stream->lastop == 'r')
		fflush(stream);
	stream->lastop = 'w';
	stream->pos = 0;
	int nWrite = size * nmemb;
	int writeSize = stream->size - stream->actual_size;
	int writeReturn = 0;
	while (nWrite != 0) {
		if (nWrite >= writeSize) {
			memcpy(&stream->buffer[stream->bufPos], &((char*)ptr)[stream->pos], nWrite);
			stream->pos += writeSize;
			stream->actual_size += writeSize;
			nWrite = nWrite - writeSize;
		}
		else if (nWrite < writeSize) {
			memcpy(&stream->buffer[stream->bufPos], &((char*)ptr)[stream->pos], nWrite);
			stream->pos += nWrite;
			stream->actual_size += nWrite;
			nWrite = 0;
		}
	}
	writeReturn = write(stream->fd, stream->buffer, stream->size);
	bzero(stream->buffer, stream->size);
	stream->actual_size = 0;
	return writeReturn;
}

int fgetc( FILE *stream ) {
	char buffer;
	int nRead;
	nRead = read(stream->fd, &buffer, 1);
	if (nRead == 0) {
		stream->eof = true;
		return EOF;
	}
	else
		return (int) buffer;
}

int fputc( int c, FILE *stream ) {
  // complete it
  return 0;
}

char *fgets( char *str, int size, FILE *stream ) {
  // complete it
  return NULL;
}

int fputs( const char *str, FILE *stream ) {
  // complete it
  return 0;
}

int feof( FILE *stream ) {
  return stream->eof == true;
}

int fseek( FILE *stream, long offset, int whence ) {
	if (whence != SEEK_SET && whence != SEEK_CUR && whence != SEEK_END)
		return -1;
	fflush(stream);
	int value = lseek(stream->fd, offset, whence);
	stream->eof = false;
	if (value == -1)
		return -1;
	return 0;
}

int fclose( FILE *stream ) {
	if (stream == NULL)
		return (EOF);
	fflush(stream);
	if (stream->bufown == true)
		delete stream->buffer;
	return close(stream->fd);
}
