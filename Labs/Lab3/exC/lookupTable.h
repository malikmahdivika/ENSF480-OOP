/*
* File Name: lookupTable.h
* Assignment: Lab 3 -- Templates and Multiple Inheritance
* Lab section: B01
* Completed by: Al Malik Mahdivika, Soummadip Sarkar
* Development Date: Sept 26, 2025
*/

#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H
#include <iostream>
#include <assert.h>
using namespace std;

// class LookupTable: GENERAL CONCEPTS
//
//    key/datum pairs are ordered.  The first pair is the pair with
//    the lowest key, the second pair is the pair with the second
//    lowest key, and so on.  This implies that you must be able to
//    compare two keys with the < operator.
//
//    Each LookupTable has an embedded iterator class that allows users
//    of the class to traverse trhough the list and  have acess to each
//    node. 

#include "customer.h"

//    In this version of the LookupTable a new struct type called Pair
//    is introduced which represents a key/data pair.

template <class T, class V> class LookupTable;
//typedef int LT_Key;
//typedef Customer LT_Datum;

template<class T, class V>
struct Pair 
{
  Pair(T keyA, V datumA):key(keyA), datum(datumA)
  {
  } 
  
  T key;
  V datum;
};

template <class T, class V>
class LT_Node {
  friend class LookupTable<T, V>;
private:
  Pair<T, V> pairM;
  LT_Node<T, V> *nextM;

  // This ctor should be convenient in insert and copy operations.
  LT_Node(const Pair<T, V>& pairA, LT_Node *nextA);
};

template <class T, class V>
class LookupTable {
 public:
  using LT_Key = T;
  using LT_Datum = V;
  
  // Nested class
  class Iterator {
    friend class LookupTable<T, V>;
    LookupTable *LT;
    LT_Node<T, V>* cursor;
    
  public:
    using LT_Key = T;
    using LT_Datum = V;
    Iterator():LT(0){}
    Iterator(LookupTable & x): LT(&x){}
    const LT_Datum&  operator *();
    const LT_Datum& operator ++();
    const LT_Datum& operator ++(int);
    int operator !();

    void step_fwd(){  assert(LT->cursor_ok());
    LT->step_fwd();}
  };

  LookupTable();
  LookupTable(const LookupTable  & source);
  LookupTable& operator =(const LookupTable& rhs);
  ~LookupTable();

  LookupTable& begin();

  int size() const;
  // PROMISES: Returns number of keys in the table.

  int cursor_ok() const;
  // PROMISES: 
  //   Returns 1 if the cursor is attached to a key/datum pair,
  //   and 0 if the cursor is in the off-list state.

  const LT_Key& cursor_key() const;
  // REQUIRES: cursor_ok()
  // PROMISES: Returns key of key/datum pair to which cursor is attached.

  const LT_Datum& cursor_datum() const;
  // REQUIRES: cursor_ok()
  // PROMISES: Returns datum of key/datum pair to which cursor is attached.

  void insert(const Pair<T, V>& pariA);
  // PROMISES:
  //   If keyA matches a key in the table, the datum for that
  //   key is set equal to datumA.
  //   If keyA does not match an existing key, keyA and datumM are
  //   used to create a new key/datum pair in the table.
  //   In either case, the cursor goes to the off-list state.

  void remove(const LT_Key& keyA);
  // PROMISES:
  //   If keyA matches a key in the table, the corresponding
  //   key/datum pair is removed from the table.
  //   If keyA does not match an existing key, the table is unchanged.
  //   In either case, the cursor goes to the off-list state.

  void find(const LT_Key& keyA);
  // PROMISES:
  //   If keyA matches a key in the table, the cursor is attached
  //   to the corresponding key/datum pair.
  //   If keyA does not match an existing key, the cursor is put in
  //   the off-list state.

  void go_to_first();
  // PROMISES: If size() > 0, cursor is moved to the first key/datum pair
  //   in the table.

  void step_fwd();
  // REQUIRES: cursor_ok()
  // PROMISES: 
  //   If cursor is at the last key/datum pair in the list, cursor
  //   goes to the off-list state.
  //   Otherwise the cursor moves forward from one pair to the next.

  void make_empty();
  // PROMISES: size() == 0.
  
  //friend ostream& operator << (ostream& os, const LookupTable<T, V>& lt);

 private:
  int sizeM;
  LT_Node<T, V> *headM;
  LT_Node<T, V> *cursorM;

  void destroy();
  // Deallocate all nodes, set headM to zero.
  
  void copy(const LookupTable& source);
  // Establishes *this as a copy of source.  Cursor of *this will
  // point to the twin of whatever the source's cursor points to.
};

#endif

template <class T, class V>
LookupTable<T, V>& LookupTable<T, V>::begin(){
  cursorM = headM;
  return *this;
}

template <class T, class V>
LT_Node<T,V>::LT_Node(const Pair<T, V>& pairA, LT_Node<T, V> *nextA)
  : pairM(pairA), nextM(nextA)
{
}

template <class T, class V>
LookupTable<T, V>::LookupTable()
  : sizeM(0), headM(0), cursorM(0)
{
}

template <class T, class V>
LookupTable<T, V>::LookupTable(const LookupTable& source)
{
  copy(source);
}

template <class T, class V>
LookupTable<T, V>& LookupTable<T, V>::operator =(const LookupTable& rhs)
{
  if (this != &rhs) {
    destroy();
    copy(rhs);
  }
  return *this;
}

template <class T, class V>
LookupTable<T, V>::~LookupTable()
{
  destroy();
}

template <class T, class V>
int LookupTable<T, V>::size() const
{
  return sizeM;
}

template <class T, class V>
int LookupTable<T, V>::cursor_ok() const
{
  return cursorM != 0;
}

template <class T, class V>
const typename LookupTable<T, V>::LT_Key& LookupTable<T, V>::cursor_key() const
{
  assert(cursor_ok());
  return cursorM->pairM.key;
}

template <class T, class V>
const typename LookupTable<T, V>::LT_Datum& LookupTable<T, V>::cursor_datum() const
{
  assert(cursor_ok());
  return cursorM->pairM.datum;
}

template <class T, class V>
void LookupTable<T, V>::insert(const Pair<T, V>& pairA)
{
  // Add new node at head?
  if (headM == 0 || pairA.key < headM->pairM.key) {
    headM = new LT_Node<T, V>(pairA, headM);
    sizeM++;
  }

  // Overwrite datum at head?
  else if (pairA.key == headM->pairM.key)
    headM->pairM.datum = pairA.datum;

  // Have to search ...

  else {
    LT_Node<T, V>* before= headM;
    LT_Node<T, V>* after=headM->nextM;

    while(after!=NULL && (pairA.key > after->pairM.key))
      {
	before=after;
	after=after->nextM;
      }
    
    if(after!=NULL && pairA.key == after->pairM.key)
      {
	after->pairM.datum = pairA.datum;
      }
    else
      {
	before->nextM = new LT_Node<T, V> (pairA, before->nextM);
	sizeM++;
      }
  }
}

template <class T, class V>
void LookupTable<T, V>::remove(const LT_Key& keyA)
{

  if (headM == 0 || keyA < headM->pairM.key)
    return;

  LT_Node<T, V>* doomed_node = 0;
  if (keyA == headM->pairM.key) {
    doomed_node = headM;
    headM = headM->nextM;
    sizeM--;
  }
  else {
    LT_Node<T, V>      *before = headM;
    LT_Node<T, V> *maybe_doomed = headM->nextM;
    while(maybe_doomed != 0 && keyA > maybe_doomed->pairM.key) {
      before = maybe_doomed;
      maybe_doomed = maybe_doomed->nextM;
    }

    if (maybe_doomed != 0 && maybe_doomed->pairM.key == keyA) {
      doomed_node = maybe_doomed;
      before->nextM = maybe_doomed->nextM;
      sizeM--;
    }      
  } 
  delete doomed_node;           // Does nothing if doomed_node == 0.
}

template <class T, class V>
void LookupTable<T, V>::find(const LT_Key& keyA)
{
  LT_Node<T, V> *ptr=headM;
  while (ptr != NULL && ptr->pairM.key != keyA)
    {
     ptr=ptr->nextM;
    }

   cursorM = ptr;
}

template <class T, class V>
void LookupTable<T, V>::go_to_first()
{
  cursorM = headM;
}

template <class T, class V>
void LookupTable<T, V>::step_fwd()
{
  assert(cursor_ok());
  cursorM = cursorM->nextM;
}

template <class T, class V>
void LookupTable<T, V>::make_empty()
{
  destroy();
  sizeM = 0;
  cursorM = 0;
}

template <class T, class V>
void LookupTable<T, V>::destroy()
{

  LT_Node<T, V> *ptr = headM;
  while (ptr!=NULL)
    {
      headM=headM->nextM;
      delete ptr;
      ptr=headM;

    }
  cursorM = NULL;
  sizeM=0;
}
template <class T, class V>
void LookupTable<T, V>::copy(const LookupTable& source)
{

  headM=0;
  cursorM =0;

  if(source.headM ==0)
    return;
 
  for(LT_Node<T, V> *p = source.headM; p != 0; p=p->nextM)
    {
      insert(Pair (p->pairM.key, p->pairM.datum));
      if(source.cursorM == p)
	find(p->pairM.key);
    }

}

template <class T, class V>
ostream& operator <<   (ostream& os, const LookupTable<T, V>& lt)
{
  if (lt.cursor_ok())
    os <<lt.cursor_key() << "  " << lt.cursor_datum();
  else
    os<<"Not Found.";

  return os;
}

template <class T, class V>
const typename LookupTable<T, V>::LT_Datum& LookupTable<T, V>::Iterator::operator *()
{
  assert(LT ->cursor_ok());
  return LT->cursor_datum();
}

template <class T, class V>
const typename LookupTable<T, V>::LT_Datum& LookupTable<T, V>::Iterator::operator ++()
{
  assert(LT->cursor_ok());
  const LT_Datum & x = LT->cursor_datum();
  LT->step_fwd();
  return x;
}

template <class T, class V>
const typename LookupTable<T, V>::LT_Datum& LookupTable<T, V>::Iterator::operator ++(int)
{
  assert(LT->cursor_ok());
 
  LT->step_fwd();
  return LT->cursor_datum();
}

template <class T, class V>
int LookupTable<T, V>::Iterator::operator!()
{
  return (LT->cursor_ok());
}


