/**
 * File name: RkTabWidget.h
 * Project: Redkite (A small GUI toolkit)
 *
 * Copyright (C) 2021 Iurie Nistor <http://iurieweb.wordpress.com>
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

#ifndef RK_TAB_WIDGET_H
#define RK_TAB_WIDGET_H

#include "RkWidget.h"

class RK_EXPORT RkTabWidget : public RkWidget {
 public:
    RkTabWidget(RkWidget *parent);
    virtual ~RkTabWidget() = default;
    void addWidget(RkWidget *widget);
    void removeWidget(RkWidget *widget);
    
 private:
    RK_DISABLE_COPY(RkTabWidget);
    RK_DISABLE_MOVE(RkTabWidget);
    RK_DELCATE_IMPL_PTR(RkTabWidget);
};

#endif // RK_TAB_WIDGET_H
