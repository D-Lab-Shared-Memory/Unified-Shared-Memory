/*
    Copyright 2018, D-Lab, DaSE@ECNU.

    Created By: Simba Wei
    Contact: simba_wei@stu.ecnu.edu.cn
    Date: 2018-11-29

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

#ifndef BLOCKHEADER_H
#define BLOCKHEADER_H
#include <iostream>

typedef long Align;  // the type of long is taken as the boundary

union defheader{
    struct info
    {
        union defheader* next_;
        unsigned long long size_; // the type of size_t restricts the size of allocated memory block should be less than 4GB
        info()
        {
            next_ = NULL;
            size_ = 0;
        };
    };
    Align x;  // force memory alignment
};

typedef union defheader blockHeader;
#endif // BLOCKHEADER_H
