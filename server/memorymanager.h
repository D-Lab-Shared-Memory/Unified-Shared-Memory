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

#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H
#include <iostream>
#include "blockheader.h"

class MemoryManager
{
public:
    MemoryManager(unsigned long long);
    ~MemoryManager()
    {
        delete[] memBlock_;
    }
public:
    /**
     * new interface for allocate memory(Main Function)
     * @param size of allocated memory
     * @return the pointer of allocated memory
     */
    char* sc_malloc(size_t);

    /**
     * release the memory that has been allocated(Main Function)
     * @param the pointer of allocated memory that should be released
     */
    void sc_free(void*);

    /**
     * destroy the memory manager, release all allocated memory
     */
    void destroy()
    {
        delete[] memBlock_;
        delete[] freeBlocks_;
    }

    /**
     * traverse over the list of free blocks
     */
    void traverse();
private:
    char* memBlock_;  //the big block of memory that will be added into unified shared memory
    blockHeader* freeBlocks_ = NULL;  //points the list of released memory blocks
};

#endif // MEMORYMANAGER_H
