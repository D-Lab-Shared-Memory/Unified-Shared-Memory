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

#include "doublylinkedlist.h"
#include <iostream>

void DoublyLinkedList::insertAfter(blockNode *node, blockNode *newNode)
{
    newNode->previous_ = node;
    newNode->next_ = node->next_;
    if(!node->next_)
    {
        lastNode_ = newNode;
    }
    else
    {
        node->next_->previous_ = newNode;
    }
    node->next_ = newNode;
    ++size_;
}

void DoublyLinkedList::insertBefore(blockNode *node, blockNode *newNode)
{
    newNode->previous_ = node->previous_;
    newNode->next_ = node;
    if(!node->previous_)
    {
        firstNode_ = newNode;
    }
    else
    {
        node->previous_->next_ = newNode;
    }
    node->previous_  = newNode;
}

void DoublyLinkedList::insertAtBeginning(blockNode * newNode)
{
    if(!firstNode_)
    {
        firstNode_ = newNode;
        lastNode_ = newNode;
        newNode->previous_ = NULL;
        newNode->next_ = NULL;
        ++size_;
    }
    else
    {
        insertBefore(firstNode_, newNode);
    }
}

void DoublyLinkedList::insertAtEnd(blockNode * newNode)
{
    if(!lastNode_)
    {
        insertAtBeginning(newNode);
    }
    else
    {
        insertAfter(lastNode_,newNode);
    }
}

void DoublyLinkedList::remove(blockNode* node)
{
    if(!node->previous_)
    {
        firstNode_ = node->next_;
    }
    else
    {
        node->previous_->next_ = node->next_;
    }
    if(!node->next_)
    {
        lastNode_ = node->previous_;
    }
    else
    {
        node->next_->previous_ = node->previous_;
    }
    --size_;
}




















