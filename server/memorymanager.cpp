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

#include "memorymanager.h"
#include <iostream>

MemoryManager::MemoryManager(unsigned long long size)
{
    // 1. allocate a big block of memory.
    memBlock_ = new char[size];

    // 2. init the memory
    blockHeader* header = (blockHeader*)memBlock_;
    header->info.next_ = header;  // link to itself
    header->info.size_ = size - sizeof(blockHeader);

    // 3. link the big block into free list
    freeBlocks_ = header;
}

char* MemoryManager::sc_malloc(size_t size)
{
    //Note: the allocated memory must be less that 4GB

    char* pointerToBlock = NULL;
    unsigned long long sizeOfFreeBlock;

    // find a free block from the free list to satisfy the requested size
    // Strategy: First Fit
    blockHeader* curr = freeBlocks_;
    blockHeader* prev = NULL;
    if(freeBlocks_)
    {
        while(curr)
        {
            // Current block is large enough
            if(curr->info.size_ >= size)
            {
                if(curr->info.size_ - size <= sizeof(blockHeader))
                {
                    // the size of rest space is less than the size of blockHeader
                    pointerToBlock = (char*)curr + sizeof(blockHeader);
                    // the previous free block links to the next block of current free block
                    if(prev)
                    {
                        prev->info.next_ = curr->info.next_;
                    }
                    else
                    {
                        freeBlocks_ = NULL;
                    }
                }
                else
                {
                    // the size of rest space is large than the size of blockHeader
                    sizeOfFreeBlock = curr->info.size_ - size - sizeof(blockHeader);
                    curr->info.size_ = sizeOfFreeBlock;
                    pointerToBlock = (char*)curr + sizeof(blockHeader) + curr->info.size_ + sizeof(blockHeader);
                }
                break;
            }
            prev = curr;
            curr = curr->info.next_;
        }

        // find a free block from the free list to satisfy the requested size
        // Strategy: best Fit
        // TO DO
    }
    else
    {
        std::cout<<"No free memory block left for malloc operation!"<<std::endl;
    }


    return pointerToBlock;
}

void MemoryManager::sc_free(void *ptr)
{
    blockHeader *p, *bp;
    bp = (blockHeader*)ptr - 1; // move pointer to the header of block belonging to ptr

    if(freeBlocks_)
    {
        // find the corresponding location in the free block list
        for(p = freeBlocks_; !(bp > p && bp < p->info.next_); p = p->info.next_)
        {
            // at the beginning or at the end of the list?
            if(p >= p->info.next_ && (bp > p || bp < p->info.next_))
            {
                break;
            }
        }

        // next, try to coalesce with previous and next free blocks
        if((char*)bp + sizeof(blockHeader) + bp->info.size_ == (char*)p->info.next_)
        {
            // can coalesce with the next free block
            bp->info.size_ = bp->info.size_ + sizeof(blockHeader) + p->info.next_->info.size_;
            bp->info.next_ = p->info.next_->info.next_;
        }
        else
        {
            // cannot coalesce with the next free block
            bp->info.next_ = p->info.next_;
        }

        if((char*)p + sizeof(blockHeader) + p->info.size_ == (char*)bp)
        {
            // can coalesce with previous free block
            p->info.size_ = p->info.size_ + sizeof(blockHeader) + bp->info.size_;
            p->info.next_ = bp->info.next_;
        }
        else
        {
            // cannot coalesce with the previous free block
            p->info.next_ = bp;
        }
        freeBlocks_ = bp; // LIFO Policy

    }
    else
    {
        // the freeBlocks_ is empty and the released block can be directly added into freeBlock_
        bp->info.next_ = bp;
        freeBlocks_ = bp;
    }
}

void MemoryManager::traverse()
{
    int counter = 0;
    blockHeader* curr = freeBlocks_;
    std::cout << "----------------- Print the available memory blocks -----------------" << "\n";
    do{
        counter++;
        std::cout << "Free block No." << counter << " : " << "size[" << curr->info.size_ <<"] "
                  << "pointer range["<< static_cast<const void*>curr << ","
                  << static_cast<const void*>((char*)curr + sizeof(blockHeader) + curr->info.size_) << "]" << "\n";
    }while((curr = curr->info.next_) != freeBlocks_);
    std::cout << "---------------------------------------------------------------------" << "\n"
}













