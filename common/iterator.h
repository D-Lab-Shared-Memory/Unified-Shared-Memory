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

#ifndef ITERATOR_H
#define ITERATOR_H

#include "blocknode.h"

class Iterator
{
public:
    Iterator(blockNode* start)
    {
        start_ = current_ = start;
    }

public:
    char* getAddrOfFreeBlock() const
    {
        return current_->addrOfFreeBlock_;
    }

    void moveToNext()
    {
        if(current_)
        {
            current_ = current_->next_;
        }
    }

    void moveToPrevious()
    {
        if(current_)
        {
            current_ = current_->previous_;
        }
    }

    bool end() const
    {
        return current_ == NULL;
    }

private:
    blockNode* start_;
    blockNode* current_;
};
#endif // ITERATOR_H
