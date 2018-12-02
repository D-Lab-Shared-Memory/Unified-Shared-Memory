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

#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include "memorymanager.h"

class ServerManager
{
public:
    ServerManager(unsigned long long size);
    ~ServerManager()
    {
        mm_->destroy();  // release all allocated memory
        delete[] mm_;
    }
private:
    MemoryManager* mm_; // the manager of the shared memory
    int role_; // represent server role: 0. storage node  1. admin node
    int port_; // network port NOTE: maybe unnecessary in RDMA network
    struct
    {
        unsigned int v4_;
        unsigned int v6_;
    } ip_; // ip address NOTE: maybe unnecessary in RDMA network
};

#endif // SERVERMANAGER_H
