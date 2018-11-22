/*
    Copyright 2018, D-Lab, DaSE@ECNU.

    Created By: Simba Wei
    Contact: simba_wei@stu.ecnu.edu.cn
    Date: 2018-11-21

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "iterator.h"

class DoublyLinkedList
{
public:
    DoublyLinkedList() : firstNode_(NULL), lastNode_(NULL), size_(0){}
    void insertAfter(blockNode*, blockNode*);
    void insertBefore(blockNode*, blockNode*);
    void insertAtBeginning(blockNode*);
    void insertAtEnd(blockNode*);
    void remove(blockNode*);
public:
    Iterator getIterator()
    {
        return Iterator(this->firstNode_);
    }

    Iterator getReverseIterator()
    {
        return Iterator(this->lastNode_);
    }
private:
    size_t size_;
private:
    blockNode* firstNode_;
    blockNode* lastNode_;
};

#endif // DOUBLYLINKEDLIST_H
