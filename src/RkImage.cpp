/**
 * File name: RkImage.cpp
 * Project: Redkite (A small GUI toolkit)
 *
 * Copyright (C) 2019 Iurie Nistor (http://quamplex.com/redkite)
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

#include "RkImage.h"
#include "RkImageImpl.h"

RkImage::RkImage()
        : o_ptr{std::make_shared<RkImageImpl>(this, nullptr, 0, 0)}
{
}

RkImage::RkImage(const unsigned char *data,
                 int width,
                 int height,
                 Format format)
        : o_ptr{std::make_shared<RkImageImpl>(this, data, width, height, format)}
{
}

RkImage::RkImage(const std::shared_ptr<RkImageImpl> &impl)
        : o_ptr{impl}
{
}

RkImage::RkImage(const RkImage &image)
{
        if (&image != this)
                o_ptr->createImage({image.width(), image.height()}, image.format(), image.data());
}

RkImage& RkImage::operator=(const RkImage &other)
{
        if (&other != this)
                o_ptr->createImage({other.width(), other.height()}, other.format(), other.data());

        return *this;
}

std::shared_ptr<RkCanvasInfo> RkImage::getCanvasInfo() const
{
        return o_ptr->getCanvasInfo();
}

const unsigned char* RkImage::data() const
{
        return o_ptr->data();
}

std::vector<unsigned char> RkImage::dataCopy() const
{
        return o_ptr->dataCopy();
}

RkImage::Format RkImage::format() const
{
        return o_ptr->format();
}

int RkImage::width() const
{
        return o_ptr->width();
}

int RkImage::height() const
{
        return o_ptr->height();
}

bool RkImage::isNull() const
{
        return o_ptr->isNull();
}
