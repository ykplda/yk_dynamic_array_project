/* 
 * File:   darray.h
 * Author: wizard
 *
 * Created on 30 June 2013, 4:29 PM
 */

#ifndef DARRAY_H
#define	DARRAY_H
struct array;
typedef struct array
{
    int *items;
    int count;
} Array;

Array * createArray();
void push(Array *, int);
int pop(Array *,int *);
void unshift(Array *,int);
int shift(Array *,int *);
void destroy(Array *);
void print(const Array *);
void straightInsertion(Array *);
#endif	/* DARRAY_H */

