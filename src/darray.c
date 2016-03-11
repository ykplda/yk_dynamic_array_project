#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <assert.h>
#include "../inc/darray.h"
/***************************
 Sorting
 ***************************/
void straightInsertion(Array *arr)
{
  int t;
  unsigned short i;
  short j;
  
  assert(arr!=NULL);
  
  for( i=0 ; i < arr->count;i++)
    {
      t = arr->items[i];
      j = i - 1;
      while( j >= 0 && t < arr->items[j])
        {
#ifndef NDEBUG
          fprintf(stdout, "DEBUG:i=%d,j=%d, m[j+1]=%d m[j]=%d\n",i,j,arr->items[j+1], arr->items[j]);
#endif  
            arr->items[j+1] = arr->items[j--];
        }
      arr->items[j+1] = t;
    }
}
/*********************************/
Array *createArray()
{
    Array *t = malloc( sizeof *t);
    if( t != NULL )
    {
        t->items = NULL;
        t->count = 0;
    }
    else
    {
        fprintf( stdout, "Memory allocation error!\n");
        abort();
    }
    return t;
}
void push(Array *arr, int item)
{
    int *t = NULL;
    assert(arr);
    t = realloc( arr->items , sizeof *arr->items * arr->count + sizeof item);
    if( t != NULL )
    {
        t[ arr->count ] = item;
        arr->items = t;
        arr->count++;       
    }
    else
    {
        fprintf(stdout, "Memory allocation error!\n");
    }
         
}
int pop(Array *arr , int *itm)
{
    int ret=1;
    int *t = NULL;
    size_t mem;
    assert( arr != NULL);
    if ( arr->count == 0) return -1;
    mem = sizeof *arr->items * arr->count - sizeof *arr->items;
    *itm = arr->items[ arr->count - 1];
    t = realloc( arr->items , mem);
    arr->items = t;
    arr->count--;
#ifndef NDEBUG
    fprintf(stdout, "DEBUG:count=%d %p\n",arr->count,arr->items);
#endif    
    return ret;
}
void unshift(Array *arr,int itm)
{
  int *t;
  size_t mem;
  assert(arr!=NULL);
  
  if( arr->items == NULL ) /*empty array*/
    {
      arr->items = malloc(sizeof *arr->items);
      assert(arr->items != NULL);
      arr->items[arr->count] = itm;
    }
  else
    {
      mem = sizeof *arr->items * arr->count;
      t = realloc(arr->items , mem + sizeof *arr->items );
      assert(t != NULL);
      arr->items = t;
      memmove(arr->items + 1 , arr->items , mem );
      *arr->items = itm;
    }
  arr->count++;
}
int shift(Array *arr, int *itm)
{
  size_t mem;
  int *t;
  assert(arr != NULL);
  if( arr->items == NULL ) return -1;
  *itm = *arr->items;
  mem = sizeof *arr->items * arr->count;
  memmove(arr->items , arr->items + 1 , mem - sizeof *arr->items);
  t = realloc( arr->items, mem - sizeof *arr->items);
  arr->items = t;
  return --arr->count;
 }
void destroy(Array *arr)
{
    Array **a;
    assert(arr != NULL);
    a = &arr;
    free(arr->items);
    *a = NULL;
    
}
void print(const Array *arr)
{
    int i;
    
    assert(arr != NULL );
    for( i = 0 ; i < arr->count; i++)
    {
        fprintf( stdout, "arr[%d]=%d\n", i, arr->items[i]);
    }
}