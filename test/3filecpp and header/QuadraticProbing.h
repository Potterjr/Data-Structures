#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

#include <vector>
#include <string>
using namespace std;

int nextPrime( int n );


template <typename HashedObj>
class HashTable
{
  public:
    explicit HashTable( int size = 101 ) : array( nextPrime( size ) )
      { makeEmpty( ); }

    bool contains( const HashedObj & x ) const
    {
        return isActive( findPos( x ) );
    }

    void makeEmpty( )
    {
        currentSize = 0;
        for( int i = 0; i < array.size( ); i++ )
            array[ i ].info = EMPTY;
    }

    bool insertint( const HashedObj & x )
    {
      
        int currentPos = findPos( x );
        if( isActive( currentPos ) )
            return false;

        array[ currentPos ] = HashEntry( x, ACTIVE );

         
        if( ++currentSize > array.size( ) / 2 )
            rehash( );

        return true;
    }

    bool remove( const HashedObj & x )
    {
        int currentPos = findPos( x );
        if( !isActive( currentPos ) )
            return false;

        array[ currentPos ].info = DELETED;
        return true;
    }

    enum EntryType { ACTIVE, EMPTY, DELETED };

    int inserttext(const HashedObj& key, int tablesize)
    {
        int hashVal = 0;

        for (int i = 0; i < key.length(); i++)
            hashVal += key[i];

        return hashVal % tablesize;
    }

  private:
    struct HashEntry
    {
        HashedObj element;
        EntryType info;

        HashEntry( const HashedObj & e = HashedObj( ), EntryType i = EMPTY )
          : element( e ), info( i ) { }
    };
    
    vector<HashEntry> array;
    int currentSize;

    bool isActive( int currentPos ) const
      { return array[ currentPos ].info == ACTIVE; }

    int findPos( const HashedObj & x ) const
    {
        int offset = 1;
        int currentPos = myhash( x );


        while( array[ currentPos ].info != EMPTY &&
                array[ currentPos ].element != x )
        {
            currentPos += offset;  
            offset += 2;
            if( currentPos >= array.size( ) )
                currentPos -= array.size( );
        }

        return currentPos;
    }

    void rehash( )
    {
        vector<HashEntry> oldArray = array;

     
        array.resize( nextPrime( 2 * oldArray.size( ) ) );
        for( int j = 0; j < array.size( ); j++ )
            array[ j ].info = EMPTY;

     
        currentSize = 0;
        for( int i = 0; i < oldArray.size( ); i++ )
            if( oldArray[ i ].info == ACTIVE )
                insertint( oldArray[ i ].element );
    }
    int myhash( const HashedObj & x ) const
    {
        int hashVal =  x ;

        hashVal %= array.size( );
        if( hashVal < 0 )
            hashVal += array.size( );

        return hashVal;
    }

 
};

int hash( const string & key );
int hash( int key );

#endif

