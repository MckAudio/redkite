/**
 * File name: RkObject.cpp
 * Project: Redkite (A small GUI toolkit)
 *
 * Copyright (C) 2020 Iurie Nistor
 *
 * This file is part of Redkite.
 *
 * Redkite is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "RkObjectImpl.h"
#include "RkLog.h"
#include "RkObserver.h"

RkObject::RkObject(RkObject *parent)
        : o_ptr{std::make_unique<RkObjectImpl>(this, parent)}
{
        if (parent)
                parent->addChild(this);
}

RkObject::~RkObject()
{
        RK_LOG_DEBUG(this << ": called");
}

RkObject* RkObject::parent() const
{
        return o_ptr->parent();
}

void RkObject::setEventQueue(RkEventQueue* queue)
{
        RK_LOG_DEBUG("called");
        o_ptr->setEventQueue(queue);
}

RkEventQueue* RkObject::eventQueue() const
{
        return o_ptr->getEventQueue();
}

void RkObject::event(RkEvent *event)
{
        RK_UNUSED(event);
}

void RkObject::rk__add_observer(std::unique_ptr<RkObserver> observer)
{
        o_ptr->addObserver(std::move(observer));
}

const std::vector<std::unique_ptr<RkObserver>>& RkObject::rk__observers() const
{
        return o_ptr->observers();
}

void RkObject::rk__add_bound_object(RkObject* obj)
{
        o_ptr->addBoundObject(obj);
}

void RkObject::addChild(RkObject* child)
{
        o_ptr->addChild(child);
}

void RkObject::removeChild(RkObject *child)
{
        o_ptr->removeChild(child);
}

void RkObject::removeObservers(RkObject *obj)
{
        o_ptr->removeObservers(obj);
}

void RkObject::removeBoundObject(RkObject *obj)
{
        o_ptr->removeBoundObject(obj);
}
