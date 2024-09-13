/**
 *  File Name: dictionaryList.cpp
 *  Assignment: ENSF 614 Fall 2024 - Lab 1 Exercise B
 *  Created by: Mahmood Moussavi
 *  Completed by: Yael Gonzalez
 *  Submission Date: September 18, 2024
 */

#include <assert.h>
#include <iostream>
#include <stdlib.h>
#include "dictionaryList.h"
#include "mystring_B.h"

using namespace std;

Node::Node(const Key &keyA, const Datum &datumA, Node *nextA)
    : keyM(keyA), datumM(datumA), nextM(nextA)
{
}

DictionaryList::DictionaryList()
    : sizeM(0), headM(0), cursorM(0)
{
}

DictionaryList::DictionaryList(const DictionaryList &source)
{
  copy(source);
}

DictionaryList &DictionaryList::operator=(const DictionaryList &rhs)
{
  if (this != &rhs)
  {
    destroy();
    copy(rhs);
  }
  return *this;
}

DictionaryList::~DictionaryList()
{
  destroy();
}

int DictionaryList::size() const
{
  return sizeM;
}

int DictionaryList::cursor_ok() const
{
  return cursorM != 0;
}

const Key &DictionaryList::cursor_key() const
{
  assert(cursor_ok());
  return cursorM->keyM;
}

const Datum &DictionaryList::cursor_datum() const
{
  assert(cursor_ok());
  return cursorM->datumM;
}

void DictionaryList::insert(const int &keyA, const Mystring &datumA)
{
  // Add new node at head?
  if (headM == 0 || keyA < headM->keyM)
  {
    headM = new Node(keyA, datumA, headM);
    sizeM++;
  }

  // Overwrite datum at head?
  else if (keyA == headM->keyM)
    headM->datumM = datumA;

  // Have to search ...
  else
  {

    // POINT ONE

    // if key is found in list, just overwrite data;
    for (Node *p = headM; p != 0; p = p->nextM)
    {
      if (keyA == p->keyM)
      {
        p->datumM = datumA;
        return;
      }
    }

    // OK, find place to insert new node ...
    Node *p = headM->nextM;
    Node *prev = headM;

    while (p != 0 && keyA > p->keyM)
    {
      prev = p;
      p = p->nextM;
    }

    prev->nextM = new Node(keyA, datumA, p);
    sizeM++;
  }
  cursorM = NULL;
}

void DictionaryList::remove(const int &keyA)
{
  if (headM == 0 || keyA < headM->keyM)
    return;

  Node *doomed_node = 0;

  if (keyA == headM->keyM)
  {
    doomed_node = headM;
    headM = headM->nextM;

    // POINT TWO
  }
  else
  {
    Node *before = headM;
    Node *maybe_doomed = headM->nextM;
    while (maybe_doomed != 0 && keyA > maybe_doomed->keyM)
    {
      before = maybe_doomed;
      maybe_doomed = maybe_doomed->nextM;
    }

    if (maybe_doomed != 0 && maybe_doomed->keyM == keyA)
    {
      doomed_node = maybe_doomed;
      before->nextM = maybe_doomed->nextM;
    }
  }
  if (doomed_node == cursorM)
    cursorM = 0;

  delete doomed_node; // Does nothing if doomed_node == 0.
  sizeM--;
}

void DictionaryList::go_to_first()
{
  cursorM = headM;
}

void DictionaryList::step_fwd()
{
  assert(cursor_ok());
  cursorM = cursorM->nextM;
}

void DictionaryList::make_empty()
{
  destroy();
  sizeM = 0;
  cursorM = 0;
}

// The following function are supposed to be completed by the stuents, as part
// of the exercise B part II. the given fucntion are in fact place-holders for
// find, destroy and copy, in order to allow successful linking when you're
// testing insert and remove. Replace them with the definitions that work.

void DictionaryList::find(const Key &keyA)
{
  for (Node *curr = headM; !curr; curr = curr->nextM)
  {
    if (curr->keyM == keyA)
    {
      cursorM = curr;
      return;
    }
  }
  cursorM = 0; // if not found put cursor in off-list state
}

void DictionaryList::destroy()
{
  while (headM)
  {
    Node *temp = headM;
    headM = temp->nextM;
    delete temp;
  }
  headM = 0;
  cursorM = 0;
  sizeM = 0;
}

void DictionaryList::copy(const DictionaryList &source)
{
  // If empty, initialize the *this with default values
  if (!source.headM)
  {
    headM = 0;
    sizeM = 0;
    cursorM = 0;
    return;
  }

  // Create a new head for the *this using source's head data
  headM = new Node(source.headM->keyM, source.headM->datumM, 0);

  // Initialize pointers to traverse source and *this lists
  Node *srcNode = source.headM->nextM;
  Node *thisNode = headM;

  // Copy the rest of the nodes from the source list to *this
  while (srcNode)
  {
    thisNode->nextM = new Node(srcNode->keyM, srcNode->datumM, 0);
    thisNode = thisNode->nextM;
    srcNode = srcNode->nextM;
  }

  // Copy the size of the source list to *this
  sizeM = source.sizeM;

  // Make cursor of this *this point to the twin of whatever the source's cursor points to
  if (source.cursorM)
  {
    Node *srcCursor = source.headM;
    Node *destCursor = headM;

    while (srcCursor != source.cursorM)
    {
      srcCursor = srcCursor->nextM;
      destCursor = destCursor->nextM;
    }
    cursorM = destCursor;
  }
  else
  {
    cursorM = 0;
  }
}
