#include "2014021_2014012_FileSystemAPI.h"
#include <unistd.h> 
#include <fcntl.h>
#include <sys/types.h>

/*
	File System Offsets	in Bytes
*/
const int superOffset = 0;
const int inodeBitmapOffset = superOffset + 4;
const int dataBitmapOffset = dataBitmapOffset + 4;
const int inodeDataOffset = dataBitmapOffset + 4;
const int dataOffset = inodeBitmapOffset + 4 * 128;


int createSFS( char* filename, int nbytes){
	/*Return values :
	-1 : File not created
	-2 : Error while writing to file 
	+ve value : File created as expected
	*/
	int return_value=open(filename, O_WRONLY | O_CREAT);
	if(return_value<0) return -1;
	int i,err;
	for(i=0;i<nbytes;i++)
	{
		err=write(return_value,"0",1);
		if(err!=1) return -2;
	}
	return return_value;	
}

int readData( int disk, int blockNum, void* block)
{
	/*Return values :
	-1 : Could not reach specified blockNum
	-1 : Error reading data
	 0 : File created as expected
	*/
	int bytes_read=4*1024;
	if(lseek(disk,blockNum*1024*4,SEEK_SET)<0) return -1;
	if(read(disk,(char*)block,bytes_read)!=bytes_read) return -2; //4KB Data Block
	return bytes_read;
}

int writeData(int disk, int blockNum, void* block){

}

int writeFile(int disk, char* filename, void* block){

}

int readFile(int disk, char* filename, void* block){
	
}