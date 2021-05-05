/**
 * File name: RkTabWidgetImpl.h
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

#ifndef RK_TAB_WIDGET_IMPL_H
#define RK_TAB_WIDGET_IMPL_H

#include "RkTabWidget.h"
#include "RkWidgetImpl.h"

class RkTabWidget::RkTabWidgetImpl : public RkWidget::RkWidgetImpl, public RkObject {
 public:
        RkTabWidgetImpl(RkTabWidget *interface,	RkWidget *parent = nullptr);
        virtual ~RkTabWidgetImpl();
	void addWidget(RkWidget *widget);
	void addRemoveWidget(RkWidget *widget);

 protected:

 private:
    RK_DECALRE_INTERFACE_PTR(RkTabWidget);
    std::unordered_set<RkWidget*> widgetList;
    RkWidget* currentWidget;
};

#endif // RK_TAB_WIDGET_IMPL_H
